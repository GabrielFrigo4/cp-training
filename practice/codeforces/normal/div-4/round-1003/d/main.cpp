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

bool a_cmp(std::pair<long, std::vector<long>> a, std::pair<long, std::vector<long>> b) {
	return std::get<0>(a) > std::get<0>(b);
}

void test_case(void) {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<long, std::vector<long>>> a(n, { 0, std::vector<long>(m) });
	for (auto &[rank, vec] : a) {
		for (auto &_v : vec) {
			std::cin >> _v;
			rank += _v;
		}
	}
	std::sort(a.begin(), a.end(), a_cmp);

	long i = m * n;
	long sum = 0;
	for (auto [_, vec] : a) {
		for (auto _v : vec) {
			sum += _v * i;
			i--;
		}
	}

	std::cout << sum << std::endl;
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