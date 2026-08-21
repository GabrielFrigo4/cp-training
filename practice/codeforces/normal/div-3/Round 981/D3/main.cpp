#include <bits/stdc++.h>
#include <algorithm>

size_t hash(uint64_t x) {
	x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
	x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
	x = x ^ (x >> 31);
	return x;
}

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int64_t> a(n);
	for (int64_t &_a : a) {
		std::cin >> _a;
	}

	std::unordered_map<size_t, int64_t> cache = {{hash(0), 0}};
	std::vector<int64_t> prefix(n+1, 0);
	cache.reserve(static_cast<size_t>(n));
	int64_t count = 0;
	for (std::size_t i = 1; i < prefix.size(); i++) {
		prefix[i] = prefix[i-1] + a[i-1];
		auto it = cache.find(hash(prefix[i]));
		if (it != cache.end() && std::get<1>(*it)== count) {
			count++;
		}
		cache[hash(prefix[i])] = count;
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
