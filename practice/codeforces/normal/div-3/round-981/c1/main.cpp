#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	for (std::size_t i = 0, j = a.size() - 1; i < j; i++, j--) {
		if (a[i] == a[i+1] || a[j] == a[j-1]) {
			std::swap(a[i+1], a[j-1]);
		}
	}

	int64_t count = 0;
	for (std::size_t i = 1; i < a.size(); i++) {
		count += a[i] == a[i-1];
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

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
