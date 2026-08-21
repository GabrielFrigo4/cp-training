#include <bits/stdc++.h>
#include <algorithm>
#define POW2(x) (1 << static_cast<int64_t>(x))

/*
k &= x	(ood)
k |= x	(even)
*/

void test_case(void) {
	int64_t n;
	std::cin >> n;

	int64_t k = 0;
	std::vector<int64_t> lista(n+1);
	for (size_t i = 0; i <= n; i++) {
		lista[i] = i;
	}
	if (n % 2 == 1) {
		k = n;
		std::swap(lista[n], lista[n]);
		std::swap(lista[n-1], lista[n-1]);
		std::swap(lista[n-2], lista[3]);
		std::swap(lista[n-3], lista[1]);
	}
	else {
		k = POW2(std::floor(std::log2(n) + 1)) - 1;
		std::swap(lista[n], lista[(k >> 1) + 1]);
		std::swap(lista[n-1], lista[(k >> 1)]);
		std::swap(lista[n-2], lista[(k >> 1) - 1]);
		std::swap(lista[n-3], lista[3]);
		std::swap(lista[n-4], lista[1]);
	}

	std::cout << k << std::endl;
	for (size_t i = 1; i <= n; i++) {
		std::cout << lista[i] << " ";
	}
	std::cout << std::endl;
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
