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
#define MAX_A 10
#pragma endregion Custom

void test_case(void) {
	long n;
	std::cin >> n;

	short bm_has = 0;
	std::vector<short> a(n);
	for (auto &_a : a) {
		std::cin >> _a;
		_a--;
		bm_has |= 1 << _a;
	}

	long count = n * (n + 1) / 2;
	std::vector<int> freq(2 * n + 1, 0);
	std::vector<int> index_eq(2 * n + 1, 0);
	std::vector<int> with_a(2 * n + 1, 0);
	std::vector<int> has_a(n + 1, 0);
	for (int i = 0; i < MAX_A; i++) {
		if ((bm_has & (1 << i)) == 0) {
			continue;
		}

		std::fill(freq.begin(), freq.end(), 0);
		freq[n] = 1;

		std::fill(index_eq.begin(), index_eq.end(), -1);
		index_eq[n] = 0;

		std::fill(with_a.begin(), with_a.end(), 0);
		std::fill(has_a.begin(), has_a.end(), 0);
		for (int j = 1; j <= n; j++) {
			has_a[j] = has_a[j - 1] + (a[j - 1] == i);
		}

		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += (-1) * (a[j] <= i) + (1) * (a[j] > i);
			if (index_eq[sum + n] >= 0 && has_a[j + 1] - has_a[index_eq[sum + n]] > 0) {
				index_eq[sum + n] = j + 1;
				with_a[sum + n] = freq[sum + n];
			}
			else if (index_eq[sum + n] < 0) {
				index_eq[sum + n] = j + 1;
			}
			freq[sum + n]++;
			count -= with_a[sum + n];
		}
	}

	std::cout << count << std::endl;
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
