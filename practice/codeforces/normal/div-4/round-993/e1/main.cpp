#pragma region Default-Include
#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Default-Include

#pragma region Include
#pragma endregion Include

#pragma region Default-Define
#define sbyte int8_t
#define short int16_t
#define int int32_t
#define long int64_t
#define byte uint8_t
#define ushort uint16_t
#define uint uint32_t
#define ulong uint64_t
#pragma endregion Default-Define

#pragma region Define
#pragma endregion Define

long ipow(long b, long e) {
	long p = 1;
	if (e == 1) {
		p = b;
	}
	if (e > 1) {
		p *= ipow(b, e/2);
		p *= ipow(b, (e+1)/2);
	}
	return p;
}

void test_case(void) {
	long k, l1, r1, l2, r2;
	std::cin >> k >> l1 >> r1 >> l2 >> r2;

	long count = 0;
	for (long x = l1; x <= r1; x++) {
		long pm = 0;
		long cc = 0;
		long n_pm = 0;
		for (long n = 0; ipow(k, n) * x <= r2; n++) {
			pm = ipow(k, n);
			if (pm * x >= l2) {
				cc++;
			}
			else {
				n_pm = pm;
			}
		}
		if (pm == 0) {
			break;
		}

		long next_x = std::min(r1, r2 / pm);
		if (n_pm != 0) {
			next_x = std::min(next_x, (l2 - 1) / n_pm);
		}
		count += (next_x + 1 - x) * cc;
		x = next_x;
	}

	std::cout << count << std::endl;
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
