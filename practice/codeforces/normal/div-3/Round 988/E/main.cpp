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
#include <string>

int64_t query1(const int64_t l, const int64_t r) {
	std::cout << "? " << l << " " << r << std::endl;
	std::cout.flush();

	int64_t answer;
	std::cin >> answer;
	return answer;
}

void query2(const std::string &bstr) {
	std::cout << "! " << bstr << std::endl;
	std::cout.flush();
}

void query3() {
	std::cout << "! IMPOSSIBLE" << std::endl;
	std::cout.flush();
}

void test_case() {
	int64_t n;
	std::cin >> n;

	std::string bstr;
	std::vector<int64_t> vans = {0};
	for (size_t i = 1; i < n; i++) {
		int64_t ans = query1(1, i + 1);
		vans.push_back(ans);
	}

	if (vans.back() == 0) {
		query3();
		return;
	}

	for (int64_t i = 1; i < vans.size(); i++) {
		if (vans[i] > vans[i-1] && vans[i-1] == 0) {
			for (size_t e = 0; e < i - vans[i]; e++) {
				bstr.push_back('1');
			}
			for (size_t e = 0; e < vans[i]; e++) {
				bstr.push_back('0');
			}
			bstr.push_back('1');
			continue;
		}
		if (vans[i] > vans[i-1] && vans[i-1] > 0) {
			bstr.push_back('1');
			continue;
		}
		if (vans[i] == vans[i-1] && vans[i-1] > 0) {
			bstr.push_back('0');
			continue;
		}
	}

	query2(bstr);
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
