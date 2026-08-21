#include <bits/stdc++.h>

struct entidade {
	int64_t x, y;
	int64_t power;
};

bool cmp(entidade e1, entidade e2) {
	return e1.power < e2.power;
}

void print_matriz(std::vector<std::vector<int64_t>> &matriz) {
	const int64_t SIZE_Y = matriz.size();
	const int64_t SIZE_X = matriz[0].size();
	
	for (int64_t y = 0; y < SIZE_Y; y++) {
		for (int64_t x = 0; x < SIZE_X; x++) {
			std::cout << matriz[y][x];
			if (x + 1 < SIZE_X) {
				std::cout << " ";
			}
			else {
				std::cout << std::endl;
			}
		}
	}
}

std::vector<std::vector<int64_t>> copy_matriz(std::vector<std::vector<int64_t>> &matriz) {
	const int64_t SIZE_Y = matriz.size();
	const int64_t SIZE_X = matriz[0].size();
	
	std::vector<std::vector<int64_t>> copy(SIZE_Y);
	for (int64_t y = 0; y < SIZE_Y; y++) {
		std::vector<int64_t> line(SIZE_X);
		copy[y] = line;
		for (int64_t x = 0; x < SIZE_X; x++) {
			copy[y][x] = matriz[y][x];
		}
	}
	return copy;
}

int main(void) {
	int64_t N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int64_t>> matriz(N);
	for (int64_t y = 0; y < N; y++) {
		std::vector<int64_t> line(M);
		matriz[y] = line;
		for (int64_t x = 0; x < M; x++) {
			int64_t P;
			std::cin >> P;
			matriz[y][x] = P;
		}
	}
	print_matriz(matriz);

	std::vector<std::vector<int64_t>> resposta(N);
	for (int64_t y = 0; y < N; y++) {
		std::vector<int64_t> line(M);
		resposta[y] = line;
		for (int64_t x = 0; x < M; x++) {
			std::vector<std::vector<int64_t>> tmp = copy_matriz(matriz);
			int64_t power = tmp[y][x];
			tmp[y][x] = -1;
		
		
			std::vector<entidade> livres;
			std::sort(livres.begin(), livres.end(), cmp);
			while () {
				
			}
			
			resposta[y][x] = 0;
		}
	}
	print_matriz(resposta);

	return 0;
}
