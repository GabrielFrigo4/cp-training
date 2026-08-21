#include <bits/stdc++.h>
#include <algorithm>

/* Divisibility
n % 33 = n % 66 = 0
n % 2 = n % 3 = n % 11 = 0 
*/

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<int16_t> numb(n+1, 3);
	numb[n] = 6;

	int64_t sum = (n % 2 == 0 ? 3 : -6);
	if ((sum == -6 && n < 5) || (sum == 3 && n < 2)) {
		std::cout << -1 << std::endl;
		return;
	}
	else if (sum == 3) {
		numb[n-1] = 6;
	}
	else if (sum == -6) {
		numb[n-1] = 6;
		numb[n-3] = 6;
	}

	for (size_t i = 1; i < numb.size(); i++) {
		std::cout << numb[i];
	}
	std::cout << std::endl;
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
