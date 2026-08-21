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
#include <set>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	int64_t score = 0;
	std::set<int64_t> repeat;
	for (int64_t _a : a) {
		if (repeat.contains(_a)) {
			repeat.erase(_a);
			score++;
		}
		else {
			repeat.insert(_a);
		}
	}

	std::cout << score << std::endl;
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
