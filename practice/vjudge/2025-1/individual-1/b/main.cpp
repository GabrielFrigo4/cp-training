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
#include <array>
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

void test_case(const long n, const std::vector<long> &a) {
	long mod_sum = 0;
	std::array<long, 3> mods{};
	for (auto _a : a) {
		mod_sum += _a;
		mod_sum %= 3;
		mods[_a % 3]++;
	}

	switch (mod_sum) {
		case 0:
			std::cout << "0" << std::endl;
			break;
		case 1:
			if (mods[1] > 0) {
				std::cout << "1" << std::endl;
			}
			else {
				std::cout << "2" << std::endl;
			}
			break;
		case 2:
			std::cout << "1" << std::endl;
			break;
	}
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t--) {
		long n;
		std::cin >> n;

		std::vector<long> a(n);
		for (auto &_a : a) {
			std::cin >> _a;
		}

		test_case(n, a);
	}
	return 0;
}