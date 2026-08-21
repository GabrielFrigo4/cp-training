#include <bits/stdc++.h>

int main(void) {
	int64_t N;
	std::cin >> N;
	
	int64_t h_max = 1;
	int64_t h_min = 100;
	std::vector<int64_t> A(N);
	for (int64_t &a : A) {
		std::cin >> a;
		if (h_max < a) {
			h_max = a;
		}
		if (h_min > a) {
			h_min = a;
		}
	}
	
	int64_t f = 0;
	std::size_t  i_last = 0;
	while (h_min < h_max) {
		std::size_t i_begin = 0, i_end = 0;
		
		for (std::size_t i = i_last; i < N; i++) {
			if (A[i] != h_min && i_begin != i_end) {
				break;
			}
			if (A[i] == h_min && i_begin == i_end) {
				i_begin = i;
				i_end = i;
			}
			if (A[i] == h_min) {
				i_end++;
				A[i]++;
				i_last = i_end;
			}
		}
		
		if (i_begin == i_end) {
			h_min++;
			i_last = 0;
		}
		else {
			f++;
		}
	}
	
	std::cout << f << std::endl;
	return 0;
}
