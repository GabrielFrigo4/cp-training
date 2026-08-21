#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector a(n, std::vector<int64_t>(n));
	for (std::vector<int64_t> &a_vec : a) {
		for (int64_t &a_item : a_vec) {
			std::cin >> a_item;
		}
	}

	int64_t count = 0;
	std::vector<int64_t> digv(2*n-1, 0);
	for (std::size_t i = 0; i < n; i++) {
		for (std::size_t j = 0; j < n; j++) {
			const std::size_t pos = j + (n-i-1);
			digv[pos] = std::max(digv[pos], std::abs(a[i][j]) * (a[i][j] < 0));
		}
	}

	std::cout << std::accumulate(digv.begin(), digv.end(), 0) << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
