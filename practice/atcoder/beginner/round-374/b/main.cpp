#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::string S, T;
	std::cin >> S >> T;

	int64_t pos = 0;
	const std::size_t size_min = std::min(S.size(), T.size());
	const std::size_t size_max = std::max(S.size(), T.size());
	for (int64_t i = 0; i <= size_min; i++) {
		if (i == size_min && size_min < size_max) {
			pos = i + 1;
			break;
		}

		if (S[i] != T[i]) {
			pos = i + 1;
			break;
		}
	}

	std::cout << pos << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
