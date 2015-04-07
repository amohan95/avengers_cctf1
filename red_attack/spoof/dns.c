#include <errno.h>
#include <limits.h>
#include <string.h>
#include "dns.h"

int build_dns_name(uint8_t *name_data, char *name[], size_t len_name)
{
	for (size_t i = 0; i < len_name; ++i) {
		/*
		 * The first 2 bytes of the label length byte must be 0, so
		 * domain names longer than 2^6 - 1 bytes cannot be encoded.
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
		name_data[off] = len_label;
		++off;
		memcpy(name_data + off, name[i], len_label);
		off += len_label;
	}

	/* terminate list of labels with null byte */
	name_data[off] = 0;

	return 0;
}

size_t len_dns_name(char *name[], size_t len_name) {
	size_t len = 0;
	
	for (size_t i = 0; i < len_name; ++i) {
		/* length byte and label string */
		len += sizeof(uint8_t) + strlen(name[i]);
	}

	/* leave room for final null byte */
	++len;

	return len;
}

void build_dns_q(uint8_t *q_data, uint8_t *name_data, size_t len_name_data)
{
	/* copy name to beginning of question */
	memcpy(q_data, name_data, len_name_data);
	union dns_q_bdy_data bdy_data = { 0 };
	/* A record */
	bdy_data.bdy.type = 1;
	/* Internet address */
	bdy_data.bdy.class = 1;
	/* copy body to end of question */
	memcpy(q_data + len_name_data, bdy_data.data, sizeof(bdy_data));
	
}

size_t len_dns_q(size_t len_name_data)
{
	return sizeof(struct dns_q_bdy) + len_name_data;
}

/*
 * Old, incorrect question builder (attempted functionality should be moved to
 * e.g. build_dns_packet_q).
 */
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
