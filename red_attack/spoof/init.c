#include <arpa/inet.h>
#include <netinet/in.h>

int si_init(struct sockaddr_in *si, char ip[], uint16_t port)
{
	si->sin_family = AF_INET;
	si->sin_port = htons(port);
	int inet_pton_ret = inet_pton(AF_INET, ip, &si->sin_addr);
	if (inet_pton_ret == 0 || inet_pton_ret == -1) {
		return inet_pton_ret;
	}
	return 0;
}

int sock_init() {
	return socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}
