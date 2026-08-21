#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	std::vector<int64_t> a_sort = a;
	std::sort(a_sort.begin(), a_sort.end());

	int64_t minimum = LLONG_MAX;
	for (size_t i = 0; i < n; i++) {
		int64_t remove = static_cast<int64_t>(i);
		if (minimum < remove) {
			break;
		}
		a_sort.erase(std::lower_bound(a_sort.begin(), a_sort.end(), a[i]));
		auto it = std::upper_bound(a_sort.begin(), a_sort.end(), a[i]);
		remove += a_sort.size() - std::distance(a_sort.begin(), it);
		minimum = std::min(minimum, remove);
	}
	std::cout << minimum << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
