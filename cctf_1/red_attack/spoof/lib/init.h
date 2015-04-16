/*
 * init provides functions for establish a network connection in order to send
 * DNS packets.
 *
 * https://www.abc.se/~m6695/udp.html
 */

#include <arpa/inet.h>

/*
 * si_init creates a sockaddr_in struct given an IP address string and a port.
 */
int si_init(struct sockaddr_in *si, char ip[], uint16_t port);

/* sock_init creates a socket file descriptor */
int sock_init();
