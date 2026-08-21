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
	int n, a;
	std::cin >> n >> a;

	std::vector<int> x(n);
	for (auto &_x : x) {
		std::cin >> _x;
	}
	std::sort(x.begin(), x.end());

	if (n == 1) {
		std::cout << 0 << std::endl;
		return;
	}

	const int dist1 = (x[n - 1] - x[1]) + std::min(std::abs(x[n - 1] - a), std::abs(x[1] - a));
	const int dist2 = (x[n - 2] - x[0]) + std::min(std::abs(x[n - 2] - a), std::abs(x[0] - a));
	std::cout << std::min(dist1, dist2) << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
