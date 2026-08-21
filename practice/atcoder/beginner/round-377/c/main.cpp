#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t N, M;
	std::cin >> N >> M;

	std::vector<int64_t> A(M);
	std::vector<int64_t> B(M);
	for (size_t i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
	}

	std::set<std::pair<int64_t, int64_t>> cap_pos;
	for (size_t i = 0; i < M; i++) {
		std::array<std::pair<int64_t, int64_t>, 9> arr_pos = {{
			{A[i], B[i]},
			{A[i]+2, B[i]+1},
			{A[i]+1, B[i]+2},
			{A[i]-1, B[i]+2},
			{A[i]-2, B[i]+1},
			{A[i]-2, B[i]-1},
			{A[i]-1, B[i]-2},
			{A[i]+1, B[i]-2},
			{A[i]+2, B[i]-1},
		}};
		for (std::pair<int64_t, int64_t> pos : arr_pos) {
			if ((std::get<0>(pos) >= 1 && std::get<1>(pos) >= 1) &&
				(std::get<0>(pos) <= N && std::get<1>(pos) <= N)) {
				cap_pos.insert(pos);
			}
		}
	}

	std::cout << N*N - cap_pos.size() << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
