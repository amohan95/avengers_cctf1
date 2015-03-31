#include <stdint.h>

/* For more info: http://www.ccs.neu.edu/home/amislove/teaching/cs4700/fall09/handouts/project1-primer.pdf */

struct dns_hdr {
	uint16_t id;
	uint16_t flags;
	uint16_t num_q;
	uint16_t num_a;
	uint16_t num_ns;
	uint16_t num_ar;
	struct dns_q *q_list;
};

// Functions to parse flags from uint16_t
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
