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

#include <string>
#include <vector>

void test_case(void) {
	std::vector<int> n;

	std::string str;
	std::cin >> str;

	long sum = 0;
	long c2 = 0, c3 = 0;
	for (char c : str){
		n.push_back(static_cast<int>(c - '0'));
		sum += n.back();
		c2 += n.back() == 2;
		c3 += n.back() == 3;
	}

	switch(sum % 9) {
		case 0:
			std::cout << "YES" << std::endl;
			break;
		case 8:
			std::cout << ((c2 >= 5 || (c2 >= 2 && c3 >= 1)) ? "YES" : "NO") << std::endl;
			break;
		case 7:
			std::cout << (c2 >= 1 ? "YES" : "NO") << std::endl;
			break;
		case 6:
			std::cout << ((c2 >= 6 || (c2 >= 3 && c3 >= 1) || c3 >= 2) ? "YES" : "NO") << std::endl;
			break;
		case 5:
			std::cout << (c2 >= 2 ? "YES" : "NO") << std::endl;
			break;
		case 4:
			std::cout << ((c2 >= 7 || (c2 >= 4 && c3 >= 1) || (c2 >= 1 && c3 >= 2)) ? "YES" : "NO") << std::endl;
			break;
		case 3:
			std::cout << ((c2 >= 3 || c3 >= 1) ? "YES" : "NO") << std::endl;
			break;
		case 2:
			std::cout << ((c2 >= 8 || (c2 >= 5 && c3 >= 1) || (c2 >= 2 && c3 >= 2)) ? "YES" : "NO") << std::endl;
			break;
		case 1:
			std::cout << ((c2 >= 4 || (c2 >= 1 && c3 >= 1)) ? "YES" : "NO") << std::endl;
			break;
		default:
			std::cout << "NO" << std::endl;
			break;
	}

	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t-- > 0) {
		test_case();
	}
	return 0;
}
