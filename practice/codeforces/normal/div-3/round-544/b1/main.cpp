#include <bits/stdc++.h>
#include <algorithm>

void test_case(void) {
	int64_t n, k;
	std::cin >> n >> k;

	std::vector<int64_t> d(n);
	for (int64_t &_d : d) {
		std::cin >> _d;
		_d %= k;
	}

	int64_t gift = 0;
	std::sort(d.begin(), d.end());
	std::size_t start = 0, finish = d.size()-1;
	while (start < finish) {
		if (d[start] == 0 && d[start + 1] == 0) {
			gift++;
			start += 2;
			continue;
		}
		if (d[start] + d[finish] == k) {
			start++;
			finish--;
			gift++;
		}
		else if (d[start] + d[finish] > k){
			finish--;
		}
		else if (d[start] + d[finish] < k) {
			start++;
		}
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
