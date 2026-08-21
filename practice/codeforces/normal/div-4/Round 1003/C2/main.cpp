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

void test_case(void) {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (auto &_a : a) {
		std::cin >> _a;
	}

	std::vector<int> b(m);
	for (auto &_b : b) {
		std::cin >> _b;
	}
	std::sort(b.begin(), b.end());

	a[0] = std::min(b[0] - a[0], a[0]);
	for (int i = 1; i < a.size(); i++) {
		auto it = std::lower_bound(b.begin(), b.end(), a[i] + a[i-1]);
		if (it != b.end()) {
			if (a[i] >= a[i - 1]) {
				a[i] = std::min(a[i], *it - a[i]);
			}
			else {
				a[i] = *it - a[i];
			}
		}
		else {
			if (a[i] < a[i - 1]) {
				std::cout << "NO" << std::endl;
				return;
			}
		}
	}

	std::cout << "YES" << std::endl;
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
