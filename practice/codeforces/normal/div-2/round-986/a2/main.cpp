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

void test_case(void) {
	int64_t n, a, b;
	std::cin >> n >> a >> b;

	std::string s;
	std::cin >> s;

	const std::pair<int64_t, int64_t> queen_pos = {a, b};
	std::pair<int64_t, int64_t> current_pos = {0, 0};
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

	for (size_t i = 0; i <= std::max(a, b) * 2; i++) {
		for (auto const [pos_a, pos_b] : pos) {
			if (queen_pos == std::make_pair(std::get<0>(current_pos) * i + pos_a, std::get<1>(current_pos) * i + pos_b)) {
				std::cout << "YES" << std::endl;
				return;
			}
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
