#include <bits/stdc++.h>
#include <algorithm>

int64_t sum(const int64_t n) {
	return n * (n - 1) / 2;
}

int64_t sum_k(const int64_t n, const int64_t k) {
	return sum(n + k) - sum(k);
}

int64_t check_index(const int64_t i, const int64_t n, const int64_t k, int64_t &ret) {
	const int64_t chunk_b = sum_k(i, k);
	const int64_t chunk_e = sum_k(n, k) - chunk_b;
	const int64_t dif = std::abs(chunk_e - chunk_b);

	const int64_t chunk_b1 = sum_k(i - 1, k);
	const int64_t chunk_e1 = sum_k(n, k) - chunk_b1;
	const int64_t dif1 = std::abs(chunk_e1 - chunk_b1);

	const int64_t chunk_b2 = sum_k(i + 1, k);
	const int64_t chunk_e2 = sum_k(n, k) - chunk_b2;
	const int64_t dif2 = std::abs(chunk_e2 - chunk_b2);

	ret = dif;
	if (dif > dif1) {
		return -1;
	}
	if (dif > dif2) {
		return 1;
	}
	return 0;
}

void test_case() {
	int64_t n, k;
	std::cin >> n >> k;

	int64_t ret, l1 = 0, l2 = n, i = (l2 + l1)/2;
	while (true) {
		int64_t flag = check_index(i, n, k, ret);
		if(flag == 1) {
			l1 = i;
		}
		else if (flag == -1) {
			l2 = i+1;
		}
		else {
			break;
		}
		i = (l2 + l1)/2;
	}

	std::cout << ret << std::endl;
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
