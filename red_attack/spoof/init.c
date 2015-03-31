#include <arpa/inet.h>
#include <netinet/in.h>

int si_init(struct sockaddr_in *si, char ip[], uint16_t port)
{
	si->sin_family = AF_INET;
	si->sin_port = htons(port);
	return inet_pton(AF_INET, ip, &si->sin_addr);
}

int sock_init() {
	return socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}
