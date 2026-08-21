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
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (auto &_a : a) {
		std::cin >> _a;
	}
	std::sort(a.begin(), a.end());

	int last = 0;
	std::vector<int> set_len;
	for (auto _a : a) {
		if (last != _a) {
			last = _a;
			set_len.push_back(1);
		}
		else {
			set_len.back()++;
		}
	}
	std::sort(set_len.begin(), set_len.end());

	int min_op = set_len.size();
	for (auto sl : set_len) {
		if (k >= sl) {
			k -= sl;
			min_op--;
		}
		else {
			break;
		}
	}

	std::cout << std::max(min_op, 1) << std::endl;
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
