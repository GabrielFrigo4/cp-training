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

#include <string>

void op(std::string &s, size_t i) {
	std::swap(s[i], s[i-1]);
	s[i-1]--;
}

void test_case(void) {
	std::string s;
	std::cin >> s;

	for (size_t i = 0; i < s.length(); i++) {
		char max = s[i];
		size_t mi = i;
		for (size_t j = i+1; j < std::min(i + 9, s.length()); j++) {
			if (max < s[j] - (j - i)) {
				max = s[j] - (j - i);
				mi = j;
			}
		}
		while (mi > i) {
			op(s, mi--);
		}
	}

	std::cout << s << std::endl;
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
