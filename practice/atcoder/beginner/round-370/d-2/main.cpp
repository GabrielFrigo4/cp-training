#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t H, W, Q;
	std::cin >> H >> W >> Q;

	std::vector<std::set<int64_t>> g1(H), g2(W);
	for (std::size_t i = 0; i < H; i++) {
		for (std::size_t j = 0; j < W; j++) {
			g1[i].insert(static_cast<int64_t>(j));
			g2[j].insert(static_cast<int64_t>(i));
		}
	}

	auto erase = [&](int64_t i, int64_t j) { g1[i].erase(j), g2[j].erase(i); };

	while (Q--) {
		int64_t R, C;
		std::cin >> R >> C;
		--R, --C;

		if (g1[R].count(C)) {
			erase(R, C);
			continue;
		}

		// up
		{
			auto it = g2[C].upper_bound(R);
			if (it != begin(g2[C])) {
				erase(*std::prev(it), C);
			}
		}
		// down
		{
			auto it = g2[C].upper_bound(R);
			if (it != end(g2[C])) {
				erase(*it, C);
			}
		}
		// left
		{
			auto it = g1[R].upper_bound(C);
			if (it != begin(g1[R])) {
				erase(R, *std::prev(it));
			}
		}
		// right
		{
			auto it = g1[R].upper_bound(C);
			if (it != end(g1[R])) {
				erase(R, *it);
			}
		}
	}
	
	int64_t ans = 0;
	for (std::size_t i = 0; i < H; i++) {
		ans += g1[i].size();
	}
	
	std::cout << ans << std::endl;
	return;
}

int32_t main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
