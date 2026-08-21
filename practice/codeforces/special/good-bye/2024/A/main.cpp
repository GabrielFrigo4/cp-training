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
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (auto &_a : a) {
		std::cin >> _a;
	}

	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (2 * a[i - 1] > a[i] && a[i - 1] < 2 * a[i]) {
			flag = true;
			break;
		}
	}

	std::cout << (flag ? "YES" : "NO") << std::endl;
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
