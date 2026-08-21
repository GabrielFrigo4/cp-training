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

void test_case(void) {
	int64_t k;
	std::cin >> k;

	std::vector<int64_t> a(k);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	std::sort(a.begin(), a.end());

	size_t li = 0, ri = a.size() - 1;
	while (li < ri) {
		if (a[li] * a[ri] > k - 2) {
			ri--;
			continue;
		}
		if (a[li] * a[ri] < k - 2) {
			li++;
			continue;
		}
		if (a[li] * a[ri] == k - 2) {
			std::cout << a[li] << " " << a[ri] << std::endl;
			break;
		}
	}
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
