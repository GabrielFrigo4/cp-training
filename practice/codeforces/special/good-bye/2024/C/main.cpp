#pragma region Default-Include
#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Default-Include

#pragma region Include
#pragma endregion Include

#pragma region Default-Define
#define sbyte int8_t
#define short int16_t
#define int int32_t
#define long int64_t
#define byte uint8_t
#define ushort uint16_t
#define uint uint32_t
#define ulong uint64_t
#pragma endregion Default-Define

#pragma region Define
#pragma endregion Define

int split_count(const int n, const int k, const int d) {
	if (n < k) return 0;
	return (n & 1) * (d / 2) + split_count(n / 2, k, d * 2);
}

void test_case(void) {
	int n, k;
	std::cin >> n >> k;

	long luck = split_count(n, k, 1);
	luck *= n + 1;
	luck += ((n + 1) / 2) * (n & 1);
	std::cout << luck << std::endl;
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
