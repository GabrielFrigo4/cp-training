#pragma region Include
#include <algorithm>
#include <iostream>
#include <iomanip>
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
#define INF_MIN -0x3f3f3f3f3f3f3f3fLL
#define INF_MAX 0x3f3f3f3f3f3f3f3fLL
#define INF(type) ((1LL << (sizeof(type) * 8 - 2)) - 1)
#pragma endregion Constant

#pragma region Custom
#pragma endregion Custom

void test_case()
{
	long n;
	std::cin >> n;

	std::vector<long> a(n);
	for (long &_a : a) {
		std::cin >> _a;
	}

	std::vector<long> b(n);
	for (long &_b : b) {
		std::cin >> _b;
	}

	long last = n;
	while(--last >= 0) {
		if (a[last] != b[last]) {
			break;
		}
	}

	long xor_a = 0;
	long xor_b = 0;
	for (long i = 0; i < n; i++) {
		xor_a ^= a[i];
		xor_b ^= b[i];
	}

	if (last == -1 || xor_a == xor_b) {
		std::cout << "Tie" << std::endl;
	} else if ((last & 1) == 0) {
		std::cout << "Ajisai" << std::endl;
	} else if ((last & 1) == 1) {
		std::cout << "Mai" << std::endl;
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t--)
	{
		test_case();
	}
	return 0;
}
