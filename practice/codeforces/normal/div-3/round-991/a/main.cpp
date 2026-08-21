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

void test_case(void) {
	long n, m;
	std::cin >> n >> m;

	long count = 0;
	while (n--) {
		std::string word;
		std::cin >> word;
		if (m - static_cast<long>(word.length()) >= 0) {
			count++;
		}
		m -= word.length();
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

	while (t-- > 0) {
		test_case();
	}
	return 0;
}
