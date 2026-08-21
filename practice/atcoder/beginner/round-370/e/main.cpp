/* https://atcoder.jp/contests/abc370/editorial/10902 */

#include <bits/stdc++.h>
#include <algorithm>

#include "atcoder/all"
using mint = atcoder::modint998244353;

void test_case(void) {
	int64_t N, K;
	std::cin >> N >> K;

	std::vector<int64_t> A(N);
	for (int64_t &a : A) {
		std::cin >> a;
	}

	std::map<int64_t, mint> M;
	M[0] = 1;
	mint all = 1;
	int64_t acc = 0;

	for (int64_t i = 0; i < N; i++) {
		acc += A[i];
		int64_t ban = acc - K;
		mint cur = all - M[ban];
		M[acc] += cur, all = all + cur;

		if (i + 1 == N) {
			std::cout << cur.val() << std::endl;
			break;
		}
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
