#include <bits/stdc++.h>
#include <algorithm>

void test_case() {
	int64_t a, b;
	std::cin >> a >> b;
	std::cout << b-a << std::endl;
	return;
}

int32_t main() {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
