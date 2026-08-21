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
#pragma endregion Custom

void test_run(void) {
	int n, c;
	std::cin >> n >> c;

	std::vector<int> a(n-1);
	for (auto &_a : a) {
		std::cin >> _a;
	}

	std::vector<int> b(n-1);
	for (auto &_b : b) {
		std::cin >> _b;
	}

	int lbs = c;
	std::vector<int> ps(n, 0);
	for (int i = 1; i < n; i++) {
		const int as = ps[i - 1] + a[i - 1];
		const int bs = ps[i - 1] + b[i - 1] + c;
		lbs += b[i - 1];
		if (bs < lbs) {
			lbs = bs;
		}

		int ms = std::min(as, bs);
		ms = std::min(ms, lbs);
		if (bs == ms) {
			lbs = bs;
		}
		ps[i] += ms;
	}

	for (auto el : ps) {
		std::cout << el << " ";
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
