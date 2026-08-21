#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>

#include <vector>
#include <set>

void test_case(void) {
	int64_t n, m, L;
	std::cin >> n >> m >> L;

	std::vector<std::pair<int64_t, int64_t>> h(n);
	for (auto &[l, r] : h) {
		std::cin >> l >> r;
	}

	std::vector<std::pair<int64_t, int64_t>> p(m);
	for (auto &[x, v] : p) {
		std::cin >> x >> v;
	}

	int64_t ind = 0;
	int64_t power = 1;
	int64_t count = 0;
	std::multiset<int64_t> powers;
	for (const auto _h : h) {
		const int64_t rpos = std::get<1>(_h) + 1;
		const int64_t lpos = std::get<0>(_h) - 1;

		while (ind < p.size() && std::get<0>(p[ind]) <= lpos) {
			powers.insert(std::get<1>(p[ind]));
			ind++;
		}

		while (power < rpos - lpos && powers.size() > 0) {
			auto it = powers.end();
			std::advance(it, -1);
			power += *it;
			powers.erase(it);
			count++;
		}

		if (power < rpos - lpos) {
			std::cout << "-1" << std::endl;
			return;
		}
	}

	std::cout << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	while (t-- > 0) {
		test_case();
	}
	return 0;
}
