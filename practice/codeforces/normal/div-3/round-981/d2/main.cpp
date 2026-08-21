#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	std::map<int64_t, int64_t> cache = {{0, 0}};
	std::vector<int64_t> prefix(n+1, 0);
	int64_t count = 0;
	for (std::size_t i = 1; i < prefix.size(); i++) {
		prefix[i] = prefix[i-1] + a[i-1];
		auto it = cache.find(prefix[i]);
		if (it != cache.end() && std::get<1>(*it)== count) {
			count++;
		}
		cache[prefix[i]] = count;
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
