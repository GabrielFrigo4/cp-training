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

void test_run(void) {
	int64_t n, m;
	std::cin >> n >> m;
	std::cin.ignore();

	std::string s;
	std::getline(std::cin, s);

	int64_t index = -1;
	for (int64_t i = 1; i <= n; i++) {
		std::string a;
		std::getline(std::cin, a);

		std::string t = a;
		t.append(" ");
		t.append(a);

		if (t.find(s) != std::string::npos) {
			index = i;
			break;
		}
	}

	std::cout << index << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
