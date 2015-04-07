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
	size_t len_name_data = len_dns_name(name, len_name);
	uint8_t name_data[len_name_data];

	if (build_dns_name(name_data, name, len_name) != 0) {
		perror("build_dns_q");
	}

	size_t len_q_data = len_dns_q(len_name_data);
	uint8_t q_data[len_q_data];
	build_dns_q(q_data, name_data, len_name_data);
	size_t len_q_packet_data = len_dns_q_packet(len_q_data);
	uint8_t q_packet_data[len_q_packet_data];
	build_dns_q_packet(q_packet_data, q_data, len_q_data, 1);

	for (size_t i = 0; i < len_q_packet_data; ++i) {
		printf("%i\n", q_packet_data[i]);
	}

	return 0;
}
