#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>

#include <string>
#include <set>

int64_t get_mul(const int64_t val, const int64_t div) {
	if (div == 0) {
		return 0;
	}
	if (val % div != 0) {
		return 0;
	}
	return val / div;
}

void test_case(void) {
	int64_t n, a, b;
	std::cin >> n >> a >> b;

	std::string s;
	std::cin >> s;

	const std::pair<int64_t, int64_t> queen_pos = {a, b};
	const std::pair<int64_t, int64_t> zero_pos = {0, 0};
	std::pair<int64_t, int64_t> current_pos = zero_pos;
	if (current_pos == queen_pos) {
		std::cout << "YES" << std::endl;
		return;
	}

	std::set<std::pair<int64_t, int64_t>> pos = {current_pos};
	for (size_t i = 0; i < s.length(); i++) {
		switch (s[i]) {
			case 'N':
				current_pos = {std::get<0>(current_pos), std::get<1>(current_pos) + 1};
				break;
			case 'E':
				current_pos = {std::get<0>(current_pos) + 1, std::get<1>(current_pos)};
				break;
			case 'S':
				current_pos = {std::get<0>(current_pos), std::get<1>(current_pos) - 1};
				break;
			case 'W':
				current_pos = {std::get<0>(current_pos) - 1, std::get<1>(current_pos)};
				break;
		}
		pos.insert(current_pos);

		if (current_pos == queen_pos) {
			std::cout << "YES" << std::endl;
			return;
		}
	}

	if (current_pos == zero_pos) {
		std::cout << "NO" << std::endl;
		return;
	}

	const int64_t disc_a = std::get<0>(current_pos);
	const int64_t disc_b = std::get<1>(current_pos);

	for (auto const [pos_a, pos_b] : pos) {
		const int64_t delta_a = a - pos_a;
		const int64_t delta_b = b - pos_b;

		const int64_t mul_a = get_mul(delta_a, disc_a);
		const int64_t mul_b = get_mul(delta_b, disc_b);
		if (mul_a < 0 || mul_b < 0) {
			continue;
		}

		if (((delta_a == disc_a * mul_a) && (delta_b == disc_b * mul_b)) &&
			((mul_a == mul_b) || (disc_a == 0) || (disc_b == 0))) {
			std::cout << "YES" << std::endl;
			return;
		}
	}

	std::cout << "NO" << std::endl;
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
