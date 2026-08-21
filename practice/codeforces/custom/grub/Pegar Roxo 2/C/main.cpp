#pragma region Include
#include <algorithm>
#include <iostream>
#include <utility>
#include <numbers>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Include

#pragma region Library
#include <vector>
#include <set>
#pragma endregion Library

#pragma region Types
#define byte uint8_t
#define short int16_t
#define int int32_t
#define long int64_t
typedef int8_t sbyte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;
#pragma endregion Types

#pragma region Constant
#undef LONG_MIN
#undef LONG_MAX
#undef ULONG_MAX
#define SBYTE_MIN SCHAR_MIN
#define SBYTE_MAX SCHAR_MAX
#define BYTE_MAX UCHAR_MAX
#define LONG_MIN LLONG_MIN
#define LONG_MAX LLONG_MAX
#define ULONG_MAX ULLONG_MAX
#pragma endregion Constant

#pragma region Custom
#define GET_EAT_SELLER(l, r, d) (((r - l) % d > 0) + ((r - l) / d))
#define GET_EAT_EDGE(l, r, d) ((r - l) / d)
#pragma endregion Custom

void test_case(void) {
	long n, m, d;
	std::cin >> n >> m >> d;

	std::set<long> s;
	for (long i = 0; i < m; i++) {
		long _s;
		std::cin >> _s;
		s.insert(_s);
	}

	long total = 1;
	long delta = 0, count = s.contains(1);
	long li = 0, mi = 0, ri = 0;

	s.insert(1);
	for (long v : s) {
		li = mi;
		mi = ri;
		ri = v;
		if (li == 0) {
			continue;
		}

		total += GET_EAT_SELLER(li, mi, d);
		if (GET_EAT_SELLER(li, mi, d) + GET_EAT_SELLER(mi, ri, d) - GET_EAT_SELLER(li, ri, d) == delta) {
			count++;
		}
		if (GET_EAT_SELLER(li, mi, d) + GET_EAT_SELLER(mi, ri, d) - GET_EAT_SELLER(li, ri, d) > delta) {
			delta = GET_EAT_SELLER(li, mi, d) + GET_EAT_SELLER(mi, ri, d) - GET_EAT_SELLER(li, ri, d);
			count = 1;
		}
	}

	li = *std::next(s.rbegin());
	mi = *s.rbegin();
	ri = n;
	total += GET_EAT_SELLER(li, mi, d) + GET_EAT_EDGE(mi, ri, d);
	if (GET_EAT_SELLER(li, mi, d) + GET_EAT_EDGE(mi, ri, d) - GET_EAT_EDGE(li, ri, d) == delta) {
		count++;
	}
	if (GET_EAT_SELLER(li, mi, d) + GET_EAT_EDGE(mi, ri, d) - GET_EAT_EDGE(li, ri, d) > delta) {
		delta = GET_EAT_SELLER(li, mi, d) + GET_EAT_EDGE(mi, ri, d) - GET_EAT_EDGE(li, ri, d);
		count = 1;
	}

	std::cout << total - delta << " " << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t--) {
		test_case();
	}
	return 0;
}
