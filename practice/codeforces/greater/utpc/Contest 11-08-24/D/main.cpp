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

bool assert(const int64_t n, const int64_t w, const int64_t b) {
	if (w + b == 0) {
		if (n == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
		return true;
	}
	if (std::min(w, b) == 0) {
		if (n % std::max(w, b) == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
		return true;
	}
	return false;
}

bool equation(const int64_t n, const int64_t w, const int64_t b, const int64_t x) {
	return ((-w * x + n) % b == 0);
}

void test_run(void) {
	int64_t n, w, b;
	std::cin >> n >> w >> b;

	if (assert(n, w, b)) {
		return;
	}

	const int64_t min_x = 0;
	const int64_t max_x = n / w;
	const int64_t delta = b / std::gcd(w, b);

	int64_t first_x = -1;
	for (int64_t x = min_x; x <= std::min(delta, max_x); x++) {
		if (equation(n, w, b, x)) {
			first_x = x;
			break;
		}
	}

	if (first_x == -1) {
		std::cout << "0" << std::endl;
		return;
	}

	const int64_t count = (max_x + delta - first_x) / delta;
	std::cout << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
