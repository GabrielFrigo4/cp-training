#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::array<std::string, 12> S;
	for (std::string &s : S) {
		std::cin >> s;
	}

	int64_t count = 0;
	for (std::size_t i = 1; i <= S.size(); i++) {
		if (S[i-1].length() == i) {
			count++;
		}
	}

	std::cout << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
