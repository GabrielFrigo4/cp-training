#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::string S;
	std::cin >> S;
	
	for (char c : S) {
		if (c != '.') {
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
