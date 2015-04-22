avengers_cctf2
==============

Blue Tasks:

1. **Develop monitoring at the server that will let you automatically check the content of HTTP requests you are getting and who is sending them. (Shuzhi)

2. **Develop monitoring software on the gateway machine that will let you automatically check if server is getting slow. (Shuzhi)
    Look at var logs.

3. *Extend your monitoring software so you can automatically get statistics on number of packets and bytes sent to the server in TCP data, TCP SYN, UDP and ICMP and Total categories so you can diagnose various DDoS attacks. Make sure the software monitors the correct interface. MONITORING VERY IMPORTANT (Weidi)

4. *Extend your monitoring software so you can detect number of packets and bytes sent to the server by each client IP. Make sure the software monitors the correct interface. MONITORING VERY IMPORTANT (Weidi)

5. Learn how you would write rules for iptables to filter traffic with some characteristics, e.g., by protocol, sender IP, length, TCP flags, etc. You may need to write those rules manually during the exercise but make sure you have tried to write them while preparing for the exercise and that they work correctly. You can check correctness by generating attack traffic with some signature (e.g., packet length, sender IP, protocol, etc.), writing a rule to filter it and checking that that traffic is dropped. You can check for drops in two ways. First, you could run your monitoring software on the interface leading to the server. Second, you could use an option with iptables that lets you see counts of times a rule was matched. It may be advisable to try both methods for measuring correctness as the first measures what goes to the server and the second shows you that the rule was activated by attack traffic. (Jerry)
    You want a Forward rule. Less Chance that you will cut you off

6. Develop defenses against Slowloris. You can do that by modifying nweb's code to detect and kill connections that have been open for a while (in a separate thread) or you can install one of the server's that is immune to Slowloris. (Hard) (Will)
    Modify the server code
    Kill all connects longer than 0.5 seconds

Red Tasks:

1. Develop attacks that flood the link between the gateway and the server. You can use flooder tool for this. Think how you can use IP spoofing and other flooder options to make this traffic hard to identify and hard to filter. (Raymond)

2. Develop attacks that may crash the server because they send malformed packets (e.g., incorrect fragments or incorrect TCP flags).The server may or may not crash when receiving these packets but give it a try. You may modify flooder's code for this. The source will be installed in /usr/local/src/flooder on client machines. You may also write your own code to use libnet directly. Libnet will be installed on client machines. (Hard, optional) (Grace - implemented smurf attack) (let's try this if we can finish everything else?)

3. Develop attacks that flood the link or the server with too many HTTP requests. You may want to script wget command for this. (Donil)

4. Develop attacks that use Slowloris. (Hard) (Ananth)
    Opens connection on the server and keeps on sending data. 

5. Test ALL your attacks and make sure they do work against your server implementation. Then iterate between trying to handle those that work against your server and trying to craft new attacks that will bring that even more hardened server down. (We can do this one together)

