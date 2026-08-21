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

#include <array>

std::array<bool, 12> specials = {
	false,
	true,
	false,
	true,
	false,
	true,
	false,
	false,
	true,
	false,
	true,
	false,
};

void test_run(void) {
	int64_t n;
	std::cin >> n;

	int64_t size = 0;
	for (auto special : specials) {
		size += (special ? 0 : 4);
	}

	int64_t count = n / size;
	int64_t rest = n % size;

	int64_t cb = count * std::accumulate(specials.begin(), specials.end(), 0);
	int64_t cw = count * (12 - std::accumulate(specials.begin(), specials.end(), 0));

	if (rest == 0) {
		std::cout << cw << " " << cb  << std::endl;
		return;
	}

	int64_t sub_size = 0;
	int64_t sub_count = 0;
	for (auto special : specials) {
		sub_count++;
		sub_size += (special ? 0 : 4);
		if (size * count + sub_size  > n) {
			std::cout << "-1" << std::endl;
			return;
		}

		if ((size * count + sub_size  == n) || ((size * count + sub_size == n - 1) && special)) {
			cb += std::accumulate(specials.begin(), specials.begin() + sub_count, 0);
			cw += (sub_count - std::accumulate(specials.begin(), specials.begin() + sub_count, 0));
			std::cout << cw << " " << cb  << std::endl;
			return;
		}
	}
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
