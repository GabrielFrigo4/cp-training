#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>

void test_case(void) {
	int64_t n, b, c;
	std::cin >> n >> b >> c;

	if (b == 0) {
		if (c < n - 2) {
			std::cout << "-1" << std::endl;
		}
		else {
			std::cout << (n - (n > c)) << std::endl;
		}
	}
	else {
		int64_t max_rem = static_cast<int64_t>(std::ceil(static_cast<double>(n - c) / static_cast<double>(b)));
		std::cout << (n - std::max(0LL, max_rem)) << std::endl;
	}
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