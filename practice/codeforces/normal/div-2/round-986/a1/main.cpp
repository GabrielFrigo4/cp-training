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

void test_case(void) {
	int64_t n, a, b;
	std::cin >> n >> a >> b;

	std::string s;
	std::cin >> s;

	std::pair<int64_t, int64_t> current_pos = {0, 0};
	std::pair<int64_t, int64_t> queen_pos = {a, b};
	for (size_t i = 0; i <= std::max(a, b) * 2; i++) {
		for (size_t e = 0; e < s.length(); e++) {
			switch (s[e]) {
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
			if (current_pos == queen_pos) {
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
