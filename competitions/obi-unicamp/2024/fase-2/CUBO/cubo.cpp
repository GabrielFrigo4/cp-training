#include <bits/stdc++.h>

int main(void) {
	int64_t N;
	std::cin >> N;
	
	int64_t f0 = (N-2)*(N-2)*(N-2);
	int64_t f1 = (N-2)*(N-2)*6;
	int64_t f2 = (N-2)*12;
	const int64_t f3 = 8;

	std::cout << f0 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	
	return 0;
}
