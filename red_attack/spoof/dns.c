#include <errno.h>
#include <limits.h>
#include <string.h>
#include "dns.h"

int build_dns_name(uint8_t *q_data, char *name[], size_t len_name)
{
	for (size_t i = 0; i < len_name; ++i) {
		/*
		 * The first 2 bytes must be 0, so domain names longer than
		 * 2^6 - 1 bytes cannot be encoded.
		 */
		if (sizeof name[i] > (1 << 6) - 1) {
			errno = EINVAL;
			return 1;
		}
	}

	size_t off = 0;

	/* copy lengths and labels into byte array */
	for (size_t i = 0; i < len_name; ++i) {
		uint8_t len_label = strlen(name[i]);
		q_data[off] = len_label;
		++off;
		memcpy(q_data + off, name[i], len_label);
		off += len_label;
	}

	q_data[off] = 0;

	return 0;
}

/*
int build_dns_q(uint8_t *q_data, uint16_t id, char *name[], size_t len_name)
{
	union dns_hdr_data hdr_data = { 0 };
	hdr_data.hdr.id = id;
	hdr_data.hdr.flags[0] = 1;
	hdr_data.hdr.qdc = 1;

	for (size_t i = 0; i < len_name; ++i) {
		if (sizeof name[i] > (1 << 6) - 1) {
			errno = EINVAL;
			return 1;
		}
	}

	size_t len_hdr_data = sizeof (struct dns_hdr);
	memcpy(q_data, hdr_data.data, len_hdr_data);
	size_t off = len_hdr_data;

	for (size_t i = 0; i < len_name; ++i) {
		uint8_t len_label = strlen(name[i]);
		q_data[off] = len_label;
		++off;
		memcpy(q_data + off, name[i], len_label);
		off += len_label;
	}

	q_data[off] = 0;

	return 0;
}
*/

size_t len_dns_name(char *name[], size_t len_name) {
	size_t len = 0;
	
	for (size_t i = 0; i < len_name; ++i) {
		len += sizeof(uint8_t) + strlen(name[i]);
	}

	/* Leave room for the final null byte */
	++len;

	return len;
}
