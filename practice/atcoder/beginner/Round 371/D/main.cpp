#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t N;
	std::cin >> N;

	std::vector<int64_t> X(N);
	for (int64_t &x : X) {
		std::cin >> x;
	}

	std::vector<int64_t> P(N);
	for (int64_t &p : P) {
		std::cin >> p;
	}

	std::vector<int64_t> SUM(N+1);
	for (std::size_t i = 1; i <= N; i++) {
		SUM[i] = SUM[i-1] + P[i-1];
	}

	int64_t Q;
	std::cin >> Q;
	for (int64_t i = 0; i < Q; i++) {
		int64_t L, R;
		std::cin >> L >> R;
		std::size_t sL = std::distance(X.begin(), std::lower_bound(X.begin(), X.end(), L));
		std::size_t sR = std::distance(X.begin(), std::upper_bound(X.begin(), X.end(), R));
		std::cout << SUM[sR] - SUM[sL] << std::endl;
	}

	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
