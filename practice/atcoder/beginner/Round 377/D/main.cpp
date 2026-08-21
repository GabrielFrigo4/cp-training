#include <bits/stdc++.h>
#include <algorithm>

int64_t get_count(const int64_t delta) {
	return delta * (delta + 1) / 2;
}

void test_run(void) {
	int64_t N, M;
	std::cin >> N >> M;

	std::vector<int64_t> L(N);
	std::vector<int64_t> R(N);
	for (size_t i = 0; i < N; i++) {
		std::cin >> L[i] >> R[i];
		L[i]--;
		R[i]--;
	}

	std::vector cache(M+1, std::vector<std::pair<int64_t, bool>>());
	for (size_t i = 0; i < N; i++) {
		cache[L[i]].push_back({i, false});
		cache[R[i]].push_back({i, true});
	}

	int64_t count = 0;
	for (size_t i = 0, j = 0, l = 0; i <= M; i++) {
		int64_t dist_max = j;
		for (std::pair<int64_t, bool> data : cache[i]) {
			if (std::get<1>(data) == true) {
				dist_max = std::max(dist_max, L[std::get<0>(data)] + 1);
			}
		}
		if (dist_max > j || i == M) {
			count += get_count(i - j) - get_count(l - j);
			j = dist_max;
			l = i;
		}
	}

	std::cout << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
