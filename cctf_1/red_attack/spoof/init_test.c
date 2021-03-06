#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "init.h"

#define BCACHE_IP "1.1.1.51"
#define WCACHE_IP "1.1.1.41"
#define TARGET_IP WCACHE_IP

int main()
{
	struct sockaddr_in si = { 0 };
	int si_init_ret = si_init(&si, TARGET_IP, 53);

	if (si_init_ret == 0) {
		fprintf(stderr, "si_init: invalid address\n");
		exit(1);
	} else if (si_init_ret == -1) {
		perror("si_init");
		exit(1);
	}

	int s = sock_init();

	if (close(s)) {
		perror("close");
		exit(1);
	}

	return 0;
}
