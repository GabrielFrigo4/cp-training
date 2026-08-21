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

#include <vector>

#define MID_MAX(x) ((x + 1) / 2)
#define MID_MIN(x) (x / 2)

void test_case(void) {
	int64_t n;
	std::cin >> n;

	if (n < 5) {
		std::cout << "-1" << std::endl;
		return;
	}

	std::vector<int64_t> a(n);
	for (int64_t i = 1; i <= MID_MAX(n); i++) {
		const size_t pos = i - 1;
		a[pos] = i*2 - 1;
	}
	std::swap(a[2], a[MID_MAX(n) - 1]);

	for (int64_t i = 1; i <= MID_MIN(n); i++) {
		const size_t pos = (n + 1) / 2 + (i - 1);
		a[pos] = i*2;
	}
	std::swap(a[MID_MAX(n)], a[MID_MAX(n) + 1]);

	for (const int64_t _a : a) {
		std::cout << _a << " ";
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	while (t-- > 0) {
		test_case();
	}
	return 0;
}
