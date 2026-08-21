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

void gcd_v2(long &a, long &b) {
	if (a == 0 || b == 0) {
		return;
	}

	if (a >= 2*b) {
		a %= (2 * b);
	}
	else if (b >= 2*a) {
		b %= (2 * a);
	}
	else {
		return;
	}

	gcd_v2(a, b);
}

void test_run(void) {
	long a, b;
	std::cin >> a >> b;

	gcd_v2(a, b);
	std::cout << a << " " << b << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
