#include <ntp_fp.h>
#include <ntp.h>
#include <ntp_stdlib.h>
#include <ntp_unixtime.h>
#include <l_stdlib.h>
#include <isc/result.h>
#include <stdio.h>

#include <sntp-opts.h>

#include "kod_management.h"
#include "networking.h"
#include "utilities.h"
#include "log.h"

#define DEBUG

int ai_fam_pref;
volatile int debug;
char adr_buf[INET6_ADDRSTRLEN];


void set_li_vn_mode (struct pkt *spkt, char leap, char version, char mode); 
int sntp_main (int argc, char **argv);
int on_wire (struct addrinfo *host);
void set_li_vn_mode (struct pkt *spkt, char leap, char version, char mode);
int set_time (double offset);



int 
main (
		int argc,
		char **argv
		) 
{
	return sntp_main(argc, argv);
}

int  
sntp_main (
		int argc, 
		char **argv
		) 
{
	register int c;
	struct kod_entry **reason = NULL;

	/* IPv6 available? */
	if (isc_net_probeipv6() != ISC_R_SUCCESS) {
		ai_fam_pref = AF_INET;
#ifdef DEBUG
		printf("No ipv6 support available, forcing ipv4\n");
#endif
	}
	else {
		/* Check for options -4 and -6 */
		if(ENABLED_OPT(IPV4))
			ai_fam_pref = AF_INET;
		else if(ENABLED_OPT(IPV6))
			ai_fam_pref = AF_INET6;
		else 
			ai_fam_pref = NULL;
	}

	log_msg("Started sntp", 0);

	int optct = optionProcess(&sntpOptions, argc, argv);
	argc -= optct;
	argv += optct; 

	/* Parse config file if declared TODO */

	/* Initialize logging system */
	if(HAVE_OPT(FILELOG)) {
		init_log((char *)OPT_ARG(FILELOG));
	}

	/* If there's a specified KOD file init KOD system. 
	 * If not and system may save to HD use default file.
	 */
	if(HAVE_OPT(KOD)) {
		kod_init_kod_db((char *)OPT_ARG(KOD));
	}
	else {
		kod_init_kod_db("sntp.kod");
	}

	/* Considering employing a variable that prevents functions of doing anything until 
	 * everything is initialized properly 
	 */
	struct addrinfo **resh = (struct addrinfo **) malloc(sizeof(struct addrinfo **));

	int resc = resolve_hosts(argv, argc, resh, ai_fam_pref);
	
	if(resc < 1) {
		/* Error! Network down? */
	}

	/* Select a certain ntp server according to simple criteria? For now
	 * let's just pay attention to previous KoDs.
	 */
	int sync_data_suc = 0;
	for(c=0; c<resc && !sync_data_suc; c++) {
		getnameinfo(resh[c]->ai_addr, resh[c]->ai_addrlen, adr_buf, 
				INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);

		int kodc;
		char *hostname = addrinfo_to_str(resh[c]);

		if((kodc = search_entry(hostname, reason)) == 0 &&
		   is_reachable(resh[c])) {
			int ow_ret = on_wire(resh[c]);
			if(ow_ret < 0) {
				printf("on_wire failed for server %s!\n", hostname);
			}
			else {
				sync_data_suc = 1;
			}
		}
		else {
			printf("KoD %i packages exists for %s, stopping any further communication.\n", 
				kodc, adr_buf);

		}

		freeaddrinfo(resh[c]);
		free(hostname);
	}

	return 0;
}

/* The heart of (S)NTP, exchange NTP packets and compute values to correct the local clock */
int
on_wire (
		struct addrinfo *host
					)
{
	register int try;
	SOCKET sock;
	
	for(try=0; try<5; try++) {
		struct pkt *x_pkt = (struct pkt *) malloc(sizeof(struct pkt));
		struct pkt *r_pkt = (struct pkt *) malloc(sizeof(struct pkt));

		struct timeval tv_xmt, tv_dst;
	
		double t21, t34, delta, offset;

		int error, rpktl, sw_case;

		char *hostname;

		l_fp p_rec, p_xmt, p_ref, p_org, xmt, tmp, dst;


		error = GETTIMEOFDAY(&tv_xmt, (struct timezone *)NULL);

#ifdef DEBUG
		printf("Current time sec: %i msec: %i\n\n", (unsigned int) tv_xmt.tv_sec, 
				(unsigned int) tv_xmt.tv_usec);
#endif

		tv_xmt.tv_sec += JAN_1970;
		TVTOTS(&tv_xmt, &xmt);
		HTONL_FP(&xmt, &(x_pkt->xmt));

		x_pkt->stratum = STRATUM_TO_PKT(STRATUM_UNSPEC);
		x_pkt->ppoll = 8;
		/* FIXME! Modus broadcast + adr. check -> bdr. pkt */
		set_li_vn_mode(x_pkt, LEAP_NOTINSYNC, 4, 3);

		create_socket(&sock, (struct sockaddr_storage *)host->ai_addr);

		sendpkt(sock, (struct sockaddr_storage *)host->ai_addr, x_pkt, LEN_PKT_NOMAC);
		rpktl = recvpkt(sock, r_pkt, x_pkt);

		close_socket(sock);

		if(rpktl > 0)
			sw_case = 1;
		else
			sw_case = rpktl;

		switch(sw_case) {
			case SERVER_UNUSEABLE:
				return -1;
				break;

			case PACKET_UNUSEABLE:
				break;

			case SERVER_AUTH_FAIL:
				break;

			case KOD_DEMOBILIZE:
				/* Received a DENY or RESTR KOD packet */
				hostname = addrinfo_to_str(host);
				add_entry(hostname, (char *) &r_pkt->refid);

				if(ENABLED_OPT(NORMALVERBOSE))
					printf("on_wire: Received KOD packet with code: %s from %s, demobilizing all connections\n", 
							(char *) r_pkt->refid, hostname);

				char *log_str = (char *) malloc(sizeof(char) * (INET6_ADDRSTRLEN + 72));
				snprintf(log_str, (INET6_ADDRSTRLEN + 72), 
					"Received a KOD packet with code %s from %s, demobilizing all connections", 
					(char *) &r_pkt->refid, hostname);

				log_msg(log_str, 2);

				free(log_msg);
				break;

			case KOD_RATE:
				/* Hmm... probably we should sleep a bit here */
				break;

			case 1:

			/* Convert timestamps from network to host byte order */
			NTOHL_FP(&r_pkt->reftime, &p_ref);
			NTOHL_FP(&r_pkt->org, &p_org);
			NTOHL_FP(&r_pkt->rec, &p_rec);
			NTOHL_FP(&r_pkt->xmt, &p_xmt);

			if(ENABLED_OPT(NORMALVERBOSE)) {
				getnameinfo(host->ai_addr, host->ai_addrlen, adr_buf, 
						INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);

				printf("\non_wire: Received %i bytes from %s\n", rpktl, adr_buf);
			}

#ifdef DEBUG
			pkt_output(r_pkt, rpktl, stdout);
	
			printf("on_wire: rpkt->reftime:\n");
			l_fp_output(&(r_pkt->reftime), stdout);
			printf("on_wire: rpkt->org:\n");
			l_fp_output(&(r_pkt->org), stdout);
			printf("on_wire: rpkt->rec:\n");
			l_fp_output(&(r_pkt->rec), stdout);
			printf("on_wire: rpkt->rec:\n");
			l_fp_output_bin(&(r_pkt->rec), stdout);
			printf("on_wire: rpkt->rec:\n");
			l_fp_output_dec(&(r_pkt->rec), stdout);
			printf("on_wire: rpkt->xmt:\n");
			l_fp_output(&(r_pkt->xmt), stdout);
#endif

			/* Compute offset etc. */
			GETTIMEOFDAY(&tv_dst, (struct timezone *)NULL);

			tv_dst.tv_sec += JAN_1970;

			tmp = p_rec;
			L_SUB(&tmp, &p_org);

			LFPTOD(&tmp, t21);

			TVTOTS(&tv_dst, &dst);

			tmp = dst;
			L_SUB(&tmp, &p_xmt);

			LFPTOD(&tmp, t34);

			offset = (t21 + t34) / 2.;
			delta = t21 - t34;


			if(ENABLED_OPT(NORMALVERBOSE))
				printf("on_wire: t21: %.6f\t t34: %.6f\ndelta: %.6f\t offset: %.6f\n", 
					t21, t34, delta, offset);

			set_time(offset); 

			return 0;
		}
	}

	char logmsg[32 + INET6_ADDRSTRLEN];
	getnameinfo(host->ai_addr, host->ai_addrlen, adr_buf, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);

	snprintf(logmsg, 32 + INET6_ADDRSTRLEN, "Received no useable packet from %s!", adr_buf);

	if(ENABLED_OPT(NORMALVERBOSE))
		printf("on_wire: Received no useable packet from %s!\n", adr_buf);


	log_msg(logmsg, 1);

	return -1;
}

/* Compute the 8 bits for li_vn_mode */
void
set_li_vn_mode (
		struct pkt *spkt,
		char leap,
		char version,
		char mode
	       ) 
{

	if(leap > 3) {
		debug_msg("set_li_vn_mode: leap > 3 using max. 3");
		leap = 3;
	}

	if(mode > 7) {
		debug_msg("set_li_vn_mode: mode > 7, using client mode 3");
		mode = 3;
	}

	spkt->li_vn_mode  = leap << 6;
	spkt->li_vn_mode |= version << 3;
	spkt->li_vn_mode |= mode;
}

/* set_time corrects the local clock by offset with either settimeofday() or by default 
 * with adjtime()/adjusttimeofday().
 */
int
set_time (
		double offset
	 )
{
	struct timeval tp;

	if(ENABLED_OPT(SETTOD)) {
		GETTIMEOFDAY(&tp, (struct timezone *)NULL);

		tp.tv_sec += (int) offset;
		tp.tv_usec += offset - (double)((int)offset);

		if(SETTIMEOFDAY(&tp, (struct timezone *)NULL) < 0) {
			if(errno == EPERM)
				printf("set_time: You don't have enough priviledges to call settimeofday(), cannot set time!\n");

			else 
				printf("set_time: settimeofday() returned with an error, couldn't set time!\n");

			return -1;
		}
		else {
			return 0;
		}
	}
	else {
		tp.tv_sec = (int) offset;
		tp.tv_usec = offset - (double)((int)offset);

		if(ADJTIMEOFDAY(&tp, NULL) < 0) {
			if(errno == EPERM)
				printf("set_time: You don't have enough priviledges to call adjtime(), cannot set time!\n");
			else 
				printf("set_time: adjtime() returned with an error, couldn't set time!\n");
			
			return -1;
		}
		else {
			return 0;
		}
	}
}
