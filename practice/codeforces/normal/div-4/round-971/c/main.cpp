#include <bits/stdc++.h>
#include <algorithm>

void test_case() {
	int64_t x, y, k;
	std::cin >> x >> y >> k;
	double dx, dy, dk;
	dx = static_cast<double>(x);
	dy = static_cast<double>(y);
	dk = static_cast<double>(k);
	const int64_t X = std::ceil(dx/dk);
	const int64_t Y = std::ceil(dy/dk);
	if (X <= Y) {
		std::cout << 2*Y << std::endl;
	}
	else {
		std::cout << 2*X - 1 << std::endl;
	}
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
