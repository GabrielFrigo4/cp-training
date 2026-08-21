#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t M;
	std::cin >> M;

	int64_t N = 0;
	int64_t maxA = 10;
	std::vector<int64_t> A;

	while (M >= 1) {
		while (std::pow(3, maxA) > M) {
			maxA--;
		}
		M -= std::pow(3, maxA);

		N++;
		A.push_back(maxA);
	}

	std::cout << N << std::endl;
	for (int64_t a : A) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
