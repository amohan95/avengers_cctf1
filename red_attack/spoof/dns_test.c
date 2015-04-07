#include <assert.h>
#include "dns.h"

void test_sizeof()
{
	assert(sizeof(struct dns_hdr) == sizeof(uint16_t) * 6);
}

int main()
{
	test_sizeof();
	return 0;
}
