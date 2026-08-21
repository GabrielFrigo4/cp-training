#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n, k;
	std::cin >> n >> k;

	std::vector<int64_t> box_count(k, 0);
	for (int64_t i = 0; i < n; i++) {
		int64_t d;
		std::cin >> d;
		box_count[d % k]++;
	}

	int64_t gift = 0;
	int64_t mod = 0;
	while (mod <= k/2) {
		if (mod == 0 || (mod == k/2 && k % 2 == 0)) {
			gift += box_count[mod]/2;
		}
		else {
			gift += std::min(box_count[mod], box_count[k - mod]);	
		}
		mod++;
	}
	
	std::cout << gift*2 << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_case();
	return 0;
}
