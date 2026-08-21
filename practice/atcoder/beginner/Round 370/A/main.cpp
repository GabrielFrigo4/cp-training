#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t L, R;
	std::cin >> L >> R;
	if (L == R) {
		std::cout << "Invalid" << std::endl;
	}
	else if (L == 1) {
		std::cout << "Yes" << std::endl;
	}
	else if (R == 1) {
		std::cout << "No" << std::endl;
	}
	return;
}

int32_t main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
