avengers_cctf1
==============

Teams
-----

### Blue

1. Develop methods for detecting that the Blue or White DNS caches have been poisoned. You can also build a monitor service that continuously queries a cache (bcache or wcache) and alerts you when a name maps to an unexpected IP (e.g., from Red's IP range). (Ananth)
2. Learn how to use the DNS cache flush service on wcache. It may be a good idea to integrate this with the monitor from task 1 so that hijacks automatically trigger a flush. (Yoo Jin)
3. Inspect the code and configuration of the DNS cache to see how it might be improved. Design patches and fix configuration errors. (Shuzhi)
4. Develop additional (optional) methods for improving DNS security (Raymond)

### Red

1. Determine how to configure your server to respond to requests for the White and Blue domains and populate your server with some Web pages. When responding to requests for Blue and White domains these Web pages should resemble the ones hosted by Blue and White web servers. (Dongil)
2. Produce mechanisms for launching DNS spoofing attack. (Jerry, Will)
3. Develop a method to determine whether your attacks work. (Weidi)

Notes
-----

Edit this part of the README with notes on what you're doing, progress you've made, things teammates should know, etc.
