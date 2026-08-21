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
#include <vector>
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

void test_case(void) {
	long n;
	std::cin >> n;

	std::vector<long> a(n);
	for (long &_a : a) {
		std::cin >> _a;
	}

	long even_len = 0;
	long odd_len = 0;
	long even_sum = 0;
	long odd_sum = 0;

	for (size_t i = 0; i < a.size(); i++) {
		if ((i & 1) == 0) {
			even_len++;
			even_sum += a[i];
		}
		else {
			odd_len++;
			odd_sum += a[i];
		}
	}

	bool work = false;
	if ((even_sum % even_len == 0) &&
		(odd_sum % odd_len == 0)) {
		work = ((even_sum / even_len) == (odd_sum / odd_len));
	}

	std::cout << (work ? "YES" : "NO") << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t-- > 0) {
		test_case();
	}
	return 0;
}
