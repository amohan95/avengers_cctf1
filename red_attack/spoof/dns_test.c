#include <stdio.h>
#include "dns.h"

#define BCACHE_HOSTNAME "bcache"
#define WCACHE_HOSTNAME "wcache"
/* Change this to the name of the experiment you're running */
#define TESTBED_HOSTNAME "cctf1-will"
#define TARGET_HOSTNAME WCACHE_HOSTNAME

int main()
{
	char *name[] = {
		TARGET_HOSTNAME,
		TESTBED_HOSTNAME,
		"USC430",
		"isi",
		"deterlab",
		"net",
	};

	size_t len_name = sizeof name / sizeof *name;
	size_t len = len_dns_q(name, len_name);
	uint8_t q_data[len];

	if (build_dns_q(q_data, 1, name, len_name) != 0) {
		perror("build_dns_q");
	}

	for (int i = 0; i < len; ++i) {
		printf("%i\n", q_data[i]);
	}

	return 0;
}
