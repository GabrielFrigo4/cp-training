#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}
	std::sort(a.begin(), a.end());
	a.push_back(a.back()+1);

	int64_t max_len = 0;
	int64_t begin = 0, end = 0;
	std::queue<int64_t> next_pos;

	int64_t bi = 0, ei = 1;
	while (ei < a.size()) {
		if (a[ei-1] < a[ei]) {
			next_pos.push(ei);
			while (a[ei-1] - a[bi] > 5) {
				bi = next_pos.front();
				next_pos.pop();
			}
			max_len = std::max(max_len, ei - bi);
		}
		ei++;
	}

	std::cout << max_len << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_case();
	return 0;
}
