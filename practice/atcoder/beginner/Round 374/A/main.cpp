#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::string S;
	std::cin >> S;
	if (S.ends_with("san")) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}

	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
