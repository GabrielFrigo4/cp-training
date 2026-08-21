#include <bits/stdc++.h>
#include <algorithm>

std::unordered_map<int64_t, int64_t> memo;
int64_t dp(std::vector<int64_t> &a, const int64_t size) {
	if (memo.contains(size)) {
		return memo[size];
	}

	int64_t maximum = size;
	for (size_t i = 1; i < a.size(); i++) {
		if (a[i] == size - i) {
			maximum = std::max(maximum, dp(a, size + i));
		}
	}
	memo[size] = maximum;
	return memo[size];
}

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	memo.clear();
	std::cout << dp(a, a.size()) << std::endl;
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
