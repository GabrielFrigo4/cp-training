#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	std::string S, T;
	std::cin >> S >> T;
	std::vector<std::string> X;

	const size_t size = std::min(S.size(), T.size());
	
	for (std::size_t i = 0; i < size; i++) {
		if (S[i] > T[i]) {
			S[i] = T[i];
			X.push_back(S);
		}
	}

	for (std::size_t i = size; i > 0; i--) {
		if (S[i-1] < T[i-1]) {
			S[i-1] = T[i-1];
			X.push_back(S);
		}
	}

	std::cout << X.size() << std::endl;
	for (std::string x : X) {
		std::cout << x << std::endl;
	}

	return;
}

int32_t main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
