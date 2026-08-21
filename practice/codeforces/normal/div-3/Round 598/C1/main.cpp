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
	int n, m, d;
	std::cin >> n >> m >> d;

	int sum = 0;
	std::vector<int> c(m);
	for (auto &_c : c) {
		std::cin >> _c;
		sum += _c;
	}

	if (d == 1 && sum < n) {
		std::cout << "NO" << std::endl;
		return;
	}

	int jump_sum = 0;
	std::vector<int> jumps;
	while (jump_sum + sum < n) {
		const int jump = std::min(d - 1, n - jump_sum - sum);
		jump_sum += jump;
		jumps.push_back(jump);
	}

	if (jumps.size() > m + 1) {
		std::cout << "NO" << std::endl;
		return;
	}

	std::cout << "YES" << std::endl;
	for (int i = 0; i < std::max(c.size(), jumps.size()); i++) {
		if (i < jumps.size()) {
			for (int j = 0; j < jumps[i]; j++) {
				std::cout << "0 ";
			}
		}
		if (i < c.size()) {
			for (int j = 0; j < c[i]; j++) {
				std::cout << (i + 1) << " ";
			}
		}
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
