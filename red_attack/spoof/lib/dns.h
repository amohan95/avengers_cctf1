/*
 * dns provides functions for creating the DNS packets necessary to execute a
 * DNS spoofing attack.
 *
 * http://www.ccs.neu.edu/home/amislove/teaching/cs4700/fall09/handouts/project1-primer.pdf
 */

#include <stddef.h>
#include <stdint.h>

/*
 * build_dns_name creates the DNS encoding of the given name and stores it in
 * q_data, and returns 0 on success.
 */
int build_dns_name(uint8_t *q_data, char *name[], size_t name_len);

/*
 * len_dns_name returns the length of the DNS encoding of the given name. */
size_t len_dns_name(char *name[], size_t name_len);

/*
 * id, qdc, ac, auc, and ad should be uint16, but this leads to issues with
 * endianness. In all of the packets we're sending and receiving, there
 * shouldn't be any values that overflow 8 bits, so we can just use the second
 * byte of the uint16 to "ensure" big-endianness. An ugly hack.
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

/*
 * To send the packet over the network, we need to serialize it into bytes. We
 * can set the values of the struct, and the byte array will be its serialized
 * form.
 */
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
	uint8_t space_type;
	uint8_t type;
	uint8_t space_class;
	uint8_t class;
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
	uint8_t space_type;
	uint8_t type;
	uint8_t space_class;
	uint8_t class;
	uint8_t space_ttl;
	uint8_t ttl;
	uint8_t space_rlength;
	uint8_t rlength;

};

struct dns_a_a {
	struct dns_label *name;
	struct dns_a_bdy bdy;
	uint32_t ip; /* 32-bit integer encoding an IP address */
};

struct dns_a_ns {
	struct dns_label *name;
	struct dns_a_bdy bdy;
	struct dns_label *ns_name;
};
