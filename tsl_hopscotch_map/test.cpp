#include "../common.c"

// https://github.com/Tessil/hopscotch-map
// cloned on 2018-09-29
#include "hopscotch_map.h"

struct Hash32 {
	inline size_t operator()(const uint32_t x) const {
		return hash32(x);
	}
};

void test_int(uint32_t n, uint32_t x0)
{
	uint32_t i, x, z = 0;
	tsl::hopscotch_map<uint32_t, uint32_t, Hash32> h;
	for (i = 0, x = x0; i < n; ++i) {
		x = hash32(x);
		z += ++h[get_key(n, x)];
	}
	fprintf(stderr, "# unique keys: %ld; checksum: %u\n", h.size(), z);
}
