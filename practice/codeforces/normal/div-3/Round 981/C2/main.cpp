#include <bits/stdc++.h>
#include <algorithm>

int64_t op(std::vector<int64_t> &a, const std::size_t i, const bool has_op) {
	const std::size_t j = a.size() - i - 1;
	int64_t c1 = 0, c2 = 0;
	int64_t last_i = i-1, last_j = j+1;
	if (has_op) {
		std::swap(last_i, last_j);
	}

	if (i > 0) {
		c1 += a[i] == a[last_i];
		c1 += a[i] == a[i+1];
		c1 += a[j] == a[j-1];
		c1 += a[j] == a[last_j];

		c2 += a[j] == a[last_i];
		c2 += a[j] == a[i+1];
		c2 += a[i] == a[j-1];
		c2 += a[i] == a[last_j];
	}
	else {
		c1 += a[i] == a[i+1];
		c1 += a[j] == a[j-1];

		c2 += a[j] == a[i+1];
		c2 += a[i] == a[j-1];
	}

	return c2 - c1;
}

typedef std::tuple<int64_t, bool> memo_t;
std::size_t hash(memo_t mem) {
	std::size_t hash = std::get<0>(mem);
	if (std::get<1>(mem)) {
		hash = ~hash;
	}
	return hash;
}

std::unordered_map<std::size_t, int64_t> memo;
int64_t dp(std::vector<int64_t> &a, const int64_t count) {
	std::size_t i = 0;
	memo[hash({i, false})] = count;
	memo[hash({i, true})] = count + op(a, i, false);

	for (i = 1; i < a.size() / 2; i++) {
		memo[hash({i, false})] = std::min(memo[hash({i-1, false})], memo[hash({i-1, true})]);
		const int64_t memo_false = memo[hash({i-1, false})] + op(a, i, false);
		const int64_t memo_true = memo[hash({i-1, true})] + op(a, i, true);
		memo[hash({i, true})] = std::min(memo_false, memo_true);
	}
	i--;

	return std::min(memo[hash({i, false})], memo[hash({i, true})]);
}

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	int64_t count = 0;
	for (std::size_t i = 1; i < a.size(); i++) {
		count += a[i] == a[i-1];
	}

	memo.clear();
	std::cout << dp(a, count) << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	for (int64_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
