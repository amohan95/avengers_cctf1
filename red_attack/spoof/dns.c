#include <limits.h>
#include "dns.h"

/*
struct dns_hdr {
	uint16_t id;
	uint16_t flags;
	uint16_t num_q;
	uint16_t num_a;
	uint16_t num_ns;
	uint16_t num_ar;
	struct dns_q *q_list;
};

int qr(struct dns_hdr *hdr);
void set_qr(int qr, struct dns_hdr *hdr);
int opcode(struct dns_hdr *hdr);
void set_opcode(int opcode, struct dns_hdr *hdr);
int aa(struct dns_hdr *hdr);
void set_aa(int aa, struct dns_hdr *hdr);
int tc(struct dns_hdr *hdr);
void set_tc(int tc, struct dns_hdr *hdr);
int rd(struct dns_hdr *hdr);
void set_rd(int rd, struct dns_hdr *hdr);
int ra(struct dns_hdr *hdr);
void set_ra(int ra, struct dns_hdr *hdr);
int z(struct dns_hdr *hdr);
void set_z(int z, struct dns_hdr *hdr);
int rcode(struct dns_hdr *hdr);
void set_rcode(int rcode, struct dns_hdr *hdr);
*/

int qr(struct dns_hdr *hdr)
{
	return hdr->flags >> ((sizeof hdr->flags) * CHAR_BIT - 1);
}

void set_qr(int qr, struct dns_hdr *hdr)
{
	if (qr) {
		hdr->flags |= 0x8000; /* 0b1000... */
	} else {
		hdr->flags &= 0x7fff; /* 0b0111... */
	}
}

int opcode(struct dns_hdr *hdr)
{
	return (hdr->flags >> 7) & 0xf;
}

void set_opcode(int opcode, struct dns_hdr *hdr)
{
	// Set any bits in opcode
	hdr->flags |= opcode << 7;
	// Reset any bits in opcode
	hdr->flags &= (opcode << 7) | 0x87ff;
}
