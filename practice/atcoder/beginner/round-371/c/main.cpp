#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t N;
	std::cin >> N;

	int64_t M_G;
	std::cin >> M_G;
	std::set<std::pair<int64_t, int64_t>> edges_G;
	for (std::size_t i = 0; i < M_G; i++) {
		int64_t u, v;
		std::cin >> u >> v;
		edges_G.emplace(u - 1, v - 1);
		edges_G.emplace(v - 1, u - 1);
	}

	int64_t M_H;
	std::cin >> M_H;
	std::set<std::pair<int64_t, int64_t>> edges_H;
	for (std::size_t i = 0; i < M_H; i++) {
		int64_t a, b;
		std::cin >> a >> b;
		edges_H.emplace(a - 1, b - 1);
		edges_H.emplace(b - 1, a - 1);
	}

	std::vector A(N, std::vector<int>(N));
	for (std::size_t i = 0; i < N; i++) {
		for (std::size_t j = i + 1; j < N; j++) {
			std::cin >> A[i][j];
			A[j][i] = A[i][j];
		}
	}

	std::vector<int64_t> P(N);
	std::iota(P.begin(), P.end(), 0);

	int64_t ans = LLONG_MAX;
	do {
		int64_t sum = 0;
		for (std::size_t i = 0; i < N; i++) {
			for (std::size_t j = 0; j < i; j++) {
				sum += A[i][j] * (edges_H.contains({i, j}) != edges_G.contains({P[i], P[j]}));
			}
		}
		ans = std::min(ans, sum);
	} while (std::ranges::next_permutation(P).found);

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
