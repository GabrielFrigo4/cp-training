#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	int64_t sum = 0;
	std::vector<int64_t> A(n);
	for (int64_t &a : A) {
		std::cin >> a;
		sum += a;
	}
	std::sort(A.begin(), A.end());

	if (n <= 2) {
		std::cout << -1 << std::endl;
		return;
	}

	const std::size_t index = A.size() / 2;
	const int64_t k = A[index]*2;
	const int64_t sum_k = k * A.size() + 1;
	const int64_t ans = std::max(static_cast<int64_t>(0), sum_k - sum);

	std::cout << ans << std::endl;
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
