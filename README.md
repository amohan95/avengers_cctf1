avengers_cctf1
==============

Teams
-----

### Blue

1. Monitor requests and traffic to identify if/when DNS poisoning has occurred for specific hosts or domains (Ananth)
2. Flush spoofed answers from the Blue DNS cache when poisoning has been detected. Flush poisoned records from White's DNS cache (using a special interface) (Yoo Jin)
3. Query wcache's DNS cache to see if White has been poisoned. Patch the DNS cache software on bcache so that it is not vulnerable. Configure the DNS cache on bcache so that it is more secure. (Shuzhi)
4. Any other detection (Raymond)

### Red

1. Receive and respond to White and Blues client requests for `*.red.net` sites. Impersonate Blue and White domains to clients that have been poisoned (Dongil)
2. Perform DNS spoofing attacks that are launched when clients acces your `*.red.net` sites (Jerry, Will)
3. Identify whether your attacks against bcache and wcache have been successful (Weidi)
