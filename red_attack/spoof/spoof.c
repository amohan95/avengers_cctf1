#include <stdlib.h>     // exit
#include <stdio.h>      // fprintf, perror
#include <unistd.h>     // close
#include "init.h"       // si_init, sock_init

int main()
{
	int s = sock_init();
	struct sockaddr_in si = { 0 };
	int si_init_ret = si_init(&si);
	if (si_init_ret == 0) {
		fprintf(stderr, "si_init: invalid address\n");
		exit(1);
	} else if (si_init_ret == -1) {
		perror("si_init");
		exit(1);
	}
	if (close(s)) {
		perror("close");
		exit(1);
	}
	return 0;
}
