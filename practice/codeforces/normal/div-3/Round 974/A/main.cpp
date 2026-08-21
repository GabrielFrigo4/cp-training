#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n, k;
	std::cin >> n >> k;

	int64_t count = 0;
	int64_t gold = 0;
	for (int64_t i = 0; i < n; i++) {
		int64_t a;
		std::cin >> a;

		if (a >= k) {
			gold += a;
		}
		if (a == 0 && gold > 0) {
			gold--;
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

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
