#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t N, M;
	std::cin >> N >> M;
	char *cache = new char[N]();

	for (std::size_t i = 0; i < M; i++) {
		int64_t A;
		char B;
		std::cin >> A >> B;

		if (cache[A-1] == '\0' && B == 'M') {
			cache[A-1] = B;
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;	
		}
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
