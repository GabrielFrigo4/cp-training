#include <bits/stdc++.h>
#include <algorithm>

void test_case() {
	int64_t n;
	std::cin >> n;
	std::vector<int64_t> output(n);
	for (int64_t &o : output) {
		std::string str;
		std::cin >> str;
		o = str.find('#') + 1;	
	}
	std::reverse(output.begin(), output.end());
	for (int64_t o : output) {
		std::cout << o << " ";
	}
	std::cout << std::endl;
	return;
}

int32_t main() {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
