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
#include <array>
#include <map>

std::array<int64_t, 7> black1 = {0, 1, 2, 2, 3, 4, 5};
std::array<int64_t, 7> black2 = {5, 4, 3, 3, 2, 1, 0};
std::map<char, int64_t> table = {
	{'C', 0},
	{'D', 1},
	{'E', 2},
	{'F', 3},
	{'G', 4},
	{'A', 5},
	{'B', 6}
};

void test_run(void) {
	std::string s1, s2;
	std::cin >> s1 >> s2;

	int64_t count = 5 + 5 * (s2[1] - s1[1]);
	count -= black1[table[s1[0]]];
	count -= black2[table[s2[0]]];
	
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
