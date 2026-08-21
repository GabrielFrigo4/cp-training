#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n, m, r, c;
	std::cin >> n >> m >> r >> c;

	int64_t count = 0;
	count += m - c;
	n -= r;
	count += (m-1)*n;
	count += (m)*n;

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
