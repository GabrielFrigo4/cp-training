#include <bits/stdc++.h>
#include <algorithm>

std::vector<std::vector<int64_t>> create_matriz(const int64_t H, const int64_t W, const int64_t value) {
	std::vector<std::vector<int64_t>> matriz(H);
	for (std::vector<int64_t> &rows : matriz) {
		rows = std::vector<int64_t>(W, value);
	}
	return matriz;
}

void test_case(void) {
	int64_t N;
	std::cin >> N;

	std::vector<std::vector<int64_t>> matriz = create_matriz(N, N, 0);
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t e = 0; e <= i; e++) {
			std::cin >> matriz[i][e];
		}
	}

	int64_t result = 0;
	for (std::size_t i = 0; i < N; i++) {
		if (result >= i) {
			result = matriz[result][i] - 1;
		}
		else {
			result = matriz[i][result] - 1;
		}
	}
	std::cout << (result + 1) << std::endl;

	return;
}

int32_t main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
