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

	std::vector<long> last(sizeof(long) * 8, n);
	for (long i = 0; i < last.size(); i++) {
		while(--last[i] >= 0) {
			if ((a[last[i]] & (1 << i)) != (b[last[i]] & (1 << i))) {
				break;
			}
		}
	}

	long xor_a = 0;
	long xor_b = 0;
	for (long i = 0; i < n; i++) {
		xor_a ^= a[i];
		xor_b ^= b[i];
	}

	for (long i = last.size() - 1; i >= 0; i--) {
		if (last[i] == -1 || (xor_a & (1 << i)) == (xor_b & (1 << i))) {
			continue;
		}
		if ((last[i] & 1) == 0) {
			std::cout << "Ajisai" << std::endl;
		}
		if ((last[i] & 1) == 1) {
			std::cout << "Mai" << std::endl;
		}
		return;
	}
	std::cout << "Tie" << std::endl;
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
