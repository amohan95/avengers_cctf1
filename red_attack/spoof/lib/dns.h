#include <stddef.h>
#include <stdint.h>

/* For more info: http://www.ccs.neu.edu/home/amislove/teaching/cs4700/fall09/handouts/project1-primer.pdf */

int build_dns_q(uint8_t *q_data, uint16_t id, char *name[], size_t len);
size_t len_dns_q(char *name[], size_t len);

/*
 * id, qdc, ac, auc, and ad should be uint16, but this leads to issues with
 * endianness. Ugly hack.
 */
struct dns_hdr {
	uint8_t space_id;
	uint8_t id;
	uint8_t flags[2];
	uint8_t space_qdc;
	uint8_t qdc;
	uint8_t space_ac;
	uint8_t ac;
	uint8_t space_auc;
	uint8_t auc;
	uint8_t space_ad;
	uint8_t ad;
};

union dns_hdr_data {
	struct dns_hdr hdr;
	uint8_t data[12];
};

/*
 * DNS packets are constructed from a fixed-length header followed by some
 * variable-sized questions or answers.
 */
struct dns_packet {

	struct dns_hdr hdr;
	struct dns_q *q;
	struct dns_a_a *a;
	/* Authority answers have the same structure as NS answers. */
	struct dns_a_ns *au;
	/*
	 * Additional records can be of any type, but the responses we will be
	 * sending will only have A records in this section, and we don't need
	 * the data in this section for any responses we receive.
	 */
	struct dns_a_a *ad;

};

struct dns_q_bdy {
	uint16_t type;
	uint16_t class;
};

/*
 * DNS questions are constructed from a variable-length name and some
 * fixed-size metadata.
 */
struct dns_q {
	struct dns_label *name;
	struct dns_q_bdy bdy;
	
};

/*
 * DNS names are constructed from a series of labels, where each label is an
 * 8-bit integer encoding the length of a domain name, followed by a string of
 * that length, terminated with a null byte. For instance, www.google.com would
 * be composed of the following bytes:
 * 
 * 	0x03 (domain name is 3 characters long)
 * 	'w'
 * 	'w'
 * 	'w'
 * 	0x06 (domain name is 6 characters long)
 * 	'g'
 * 	'o'
 * 	'o'
 * 	'g'
 * 	'l'
 * 	'e'
 * 	0x03 (domain name is 3 characters long)
 * 	'c'
 * 	'o'
 * 	'm'
 * 	0x00 (end of name)
 */
struct dns_label {
	uint8_t len;
	char label[];
};

struct dns_a_bdy {
	uint16_t type;
	uint16_t class;
	uint16_t ttl;
	uint16_t rlength;

};

struct dns_a_a {
	struct dns_label *name;
	struct dns_a_bdy bdy;
	uint32_t ip; /* 32-bit integer encoding an IP address */
};

struct dns_a_ns {
	struct dns_label *name; /* name */
	struct dns_a_bdy bdy;
	struct dns_label *ns_name;
};
