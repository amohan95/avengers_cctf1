#include <stdint.h>

/* For more info: http://www.ccs.neu.edu/home/amislove/teaching/cs4700/fall09/handouts/project1-primer.pdf */

struct dns_hdr {
	uint16_t id;
	uint16_t qr : 1;
	uint16_t opcode : 4;
	uint16_t aa : 1;
	uint16_t tc : 1;
	uint16_t rd : 1;
	uint16_t ra : 1;
	uint16_t z : 3;
	uint16_t rcode : 4;
	uint16_t num_q;
	uint16_t num_a;
	uint16_t num_ns;
	uint16_t num_ar;
	struct dns_q *q_list;
};
