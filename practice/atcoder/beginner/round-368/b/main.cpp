#include <bits/stdc++.h>
#include <algorithm>

void test_case() {
	int32_t N;
	std::cin >> N;

	std::vector<int32_t> list(N);
	for (int32_t &element : list) {
		std::cin >> element;
	}

	int32_t loops = 0;
	while(true) {
		std::sort(list.begin(), list.end(), std::greater<int32_t>());
		if (list[1] <= 0) {
			break;
		}
		loops++;
		list[0]--;
		list[1]--;
	}
	
	std::cout << loops << std::endl;
	return;
}

int32_t main() {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
