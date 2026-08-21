#include <bits/stdc++.h>
#include <algorithm>

int64_t get_count(std::vector<bool> &y1, std::vector<bool> &y2, const int64_t sum1, const int64_t sum2) {
	int64_t count = 0;
	int64_t cache = 0;
	const int64_t max_index = std::max(y1.size(), y2.size());
	for (int64_t i = 0; i < max_index; i++) {
		if (y1[i] && y2[i]) {
			count += sum1 + sum2 - 2;
		}
		if (i > 0 && i < max_index-1) {
			if (y1[i] && y2[i-1] && y2[i+1]) {
				count++;
			}
			if (y2[i] && y1[i-1] && y1[i+1]) {
				count++;
			}
		}
	}
	return count;
}

void test_case() {
	int64_t n;
	std::cin >> n;
	std::vector<bool> y0(n + 1), y1(n + 1);
	for (int64_t i = 0; i < n; i++) {
		int64_t x, y;
		std::cin >> x >> y;
		switch (y) {
			case 0:
				y0[x] = true;
				break;
			case 1:
				y1[x] = true;
				break;
		}
	}
	std::vector<int64_t> sum0(n + 2), sum1(n + 2);
	for (int64_t i = 1; i <= n + 1; i++) {
		sum0[i] = sum0[i - 1] + y0[i - 1];
		sum1[i] = sum1[i - 1] + y1[i - 1];
	}
	std::cout << get_count(y0, y1, sum0.back(), sum1.back()) << std::endl;
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
