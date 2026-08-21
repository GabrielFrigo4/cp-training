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
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n);
	for (auto &_a : a) {
		std::cin >> _a;
	}
	const int pv = a.front();
	std::sort(a.rbegin(), a.rend());

	std::vector<int> b(m);
	for (auto &_b : b) {
		std::cin >> _b;
	}
	std::sort(b.rbegin(), b.rend());

	std::vector<int> c(m);
	int li = n - 1;
	for (int i = m - 1; i >= 0; i--) {
		while (li >= 0 && a[li] < b[i]) {
			li--;
		}
		c[i] = (b[i] <= pv ? 0 : li + 1);
	}

	for (int k = 1; k <= m; k++) {
		const int rem = m % k;
		const int con = m / k;

		const auto it = std::upper_bound(b.rbegin(), b.rend(), pv);
		const int dist = std::abs(std::distance(b.rend(), it) + 1);

		long pos = con;
		if (it != b.rend()) {
			for (int i = dist - rem; i >= 0; i -= k) {
				pos += c[i];
			}	
		}
		std::cout << pos << " ";
	}

	std::cout << std::endl;
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
