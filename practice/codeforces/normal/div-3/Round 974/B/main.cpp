#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n, k;
	std::cin >> n >> k;

	if ((k % 4 == 0) || (k % 4 == 3 && n % 2 == 1) || (k % 4 == 1 && n % 2 == 0)) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
