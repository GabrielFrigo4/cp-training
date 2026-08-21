#include <bits/stdc++.h>
#include <algorithm>

void test_case() {
	int32_t N, K;
	std::cin >> N >> K;

	std::vector<int32_t> stack(N);
	for (int32_t i = 0; i < N-K; i++) {	
		int32_t A;
		std::cin >> A;
		stack[K+i] = A;
	}
	for (int32_t i = 0; i < K; i++) {
		int32_t A;
		std::cin >> A;
		stack[i] = A;
	}

	for (int32_t res : stack) {
		std::cout << res << " ";
	}
	std::cout << std::endl;
	return;
}

int32_t main() {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
