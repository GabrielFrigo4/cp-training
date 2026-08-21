#include <bits/stdc++.h>

void print_pista(std::vector<int64_t> pista, const int64_t N, const int64_t M) {
	for (int64_t i = 0; i < pista.size(); i++) {
		std::cout << pista[i];
		if ((i+1) % M == 0) {
			std::cout << std::endl;
		}
		else {
			std::cout << " ";
		}
	}
}

int64_t get_pos(const int64_t M, int64_t n, int64_t m) {
	int64_t pos = M*(n-1) + (m-1);
	return pos;
}

int64_t get_element(const int64_t M, int64_t n, int64_t m) {
	int64_t pos = M*(n-1) + m;
	return pos;
}

int main(void) {
	int64_t N, M, P;
	std::cin >> N >> M >> P;

	std::vector<int64_t> pista(N*M);
	for (int64_t i = 0; i < N*M; i++) {
		pista[i] = i+1;
	}

	std::vector<int64_t> pos_N(N);
	for (int64_t i = 0; i < N; i++) {
		pos_N[i] = i+1;
	}

	std::vector<int64_t> pos_M(M);
	for (int64_t i = 0; i < M; i++) {
		pos_M[i] = i+1;
	}

	for (int64_t i = 0; i < P; i++) {
		char cmd;
		int64_t a, b;
		std::cin >> cmd >> a >> b;

		switch (cmd) {
			case 'L':
				std::swap(pos_N[a-1], pos_N[b-1]);
				break;
			case 'C':
				std::swap(pos_M[a-1], pos_M[b-1]);
				break;
		}
	}

	
	for (int64_t i = 1; i <= N; i++) {
		for (int64_t e = 1; e <= M; e++) {
			pista[get_pos(M, i, e)] = get_element(M, pos_N[i-1], pos_M[e-1]);
		}
	}

	print_pista(pista, N, M);
	return 0;
}
