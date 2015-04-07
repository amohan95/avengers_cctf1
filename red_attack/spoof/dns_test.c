#include <stdio.h>
#include "dns.h"

#define BCACHE_HOSTNAME "bcache"
#define WCACHE_HOSTNAME "wcache"
/* Change this to the name of the experiment you're running */
#define TESTBED_HOSTNAME "cctf1-will"
#define TARGET_HOSTNAME WCACHE_HOSTNAME

int main()
{
	char *name_raw[] = {
		TARGET_HOSTNAME,
		TESTBED_HOSTNAME,
		"USC430",
		"isi",
		"deterlab",
		"net",
	};

	size_t len_name_raw = sizeof name_raw / sizeof *name_raw;
	size_t len_name = len_dns_name(name_raw, len_name_raw);
	uint8_t q_data[len_name];

	if (build_dns_name(q_data, name_raw, len_name_raw) != 0) {
		perror("build_dns_q");
	}

	for (size_t i = 0; i < len_name; ++i) {
		printf("%i\n", q_data[i]);
	}

	return 0;
}
