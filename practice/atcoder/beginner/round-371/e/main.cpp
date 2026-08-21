#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t N;
	std::cin >> N;

	std::vector pos(N+1, std::vector<int64_t>());
	for (std::size_t i = 1; i <= N; i++) {
		int64_t a;
		std::cin >> a;
		pos[a].push_back(static_cast<int64_t>(i));
	}

	int64_t ans = 0;
	for (std::size_t i = 0; i <= N; i++) {
		if (pos[i].size() > 0) {
			int64_t cnt = N * (N + 1) / 2;
			std::vector<int64_t> p = pos[i];
			p.insert(p.begin(), 0);
			p.push_back(N+1);
			for (std::size_t j = 1; j < p.size(); j++) {
				cnt -= (p[j] - p[j - 1] - 1) * (p[j] - p[j - 1]) / 2;
			}
			ans += cnt;
		}
	}

	std::cout << ans << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
