#include <bits/stdc++.h>
#include <algorithm>

int64_t dp(const std::vector<int64_t> &K, std::map<std::pair<int64_t, int64_t>, int64_t> &memo, const int64_t index, const int64_t sum) {
	if (index < 0) {
		return std::abs(sum);
	}

	if (memo.find({index, sum}) != memo.end()) {
		return std::abs(memo[{index, sum}]);
	}

	int64_t positive = dp(K, memo, index - 1, sum + K[index]);
	int64_t negative = dp(K, memo, index - 1, sum - K[index]);
	memo[{index, sum}] = std::min(positive, negative);
	return std::abs(memo[{index, sum}]);
}

void test_run(void) {
	int64_t N;
	std::cin >> N;

	std::vector<int64_t> K(N);
	for (int64_t &k : K) {
		std::cin >> k;
	}

	std::map<std::pair<int64_t, int64_t>, int64_t> memo;
	std::cout << (std::accumulate(K.begin(), K.end(), 0) + dp(K, memo, N - 1, 0)) / 2 << std::endl;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
