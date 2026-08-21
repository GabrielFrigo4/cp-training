#include <bits/stdc++.h>
#include <algorithm>

bool get_bit(int32_t numb, std::size_t index) {
	return (numb & (1 << index)) != 0;
}

int64_t dif(const std::vector<int64_t> &K, const int32_t ord) {
	int64_t s1 = 0, s2 = 0;
	for (std::size_t i = 0; i < K.size(); i++) {
		bool bit = get_bit(ord, i);
		s1 += K[i] * bit;
		s2 += K[i] * (1 - bit);
	}
	return std::max(s1, s2);
}

void test_run(void) {
	int64_t N;
	std::cin >> N;

	std::vector<int64_t> K(N);
	for (int64_t &k : K) {
		std::cin >> k;
	}

	int64_t sum_mm = LLONG_MAX;
	for (int32_t ord = 0; ord < (1 << N); ord++) {
		sum_mm = std::min(sum_mm, dif(K, ord));
	}

	std::cout << sum_mm << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
