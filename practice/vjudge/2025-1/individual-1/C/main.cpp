#pragma region Include
#include <algorithm>
#include <iostream>
#include <utility>
//#include <numbers>
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

void test_case(std::vector<bool> &a) {
	int t = 0;
	int k = 0;
	for (bool e : a) {
		if (e) {
			k++;
		}
		else {
			t += (k > 0);
			k -= (k > 0);
		}
	}
	std::cout << t << std::endl;
	return;
}

int main(void) {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	std::vector<bool> a(2*t, false);
	while (t--) {
		int e;
		std::cin >> e;
		a[--e] = true;
	}
	test_case(a);
	return 0;
}
