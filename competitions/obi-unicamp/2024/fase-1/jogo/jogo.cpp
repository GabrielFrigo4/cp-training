#include <bits/stdc++.h>
#define VIVA 1
#define MORTA 0

int16_t get_point(int16_t x, int16_t y, int16_t **matriz, int16_t N){
	if(x < 0 || x >= N){
		return 0;
	}
	else if(y < 0 || y >= N){
		return 0;
	}
	else{
		return matriz[y][x];
	}
}

int16_t **make_matriz(int16_t N){
	int16_t **matriz = (int16_t **)malloc(sizeof(int16_t *) * N);
	for(int16_t y = 0; y < N; y++){
		matriz[y] = (int16_t *)malloc(sizeof(int16_t) * N);
	}
	return matriz;
}

void copy_matriz(int16_t **src_matriz, int16_t **dest_matriz, int16_t N){
	for(int16_t y = 0; y < N; y++){
		for(int16_t x = 0; x < N; x++){
			dest_matriz[y][x] = src_matriz[y][x];
		}
	}
}

void update_matriz(int16_t **src_matriz, int16_t **dest_matriz, int16_t N){
	for(int16_t y = 0; y < N; y++){
		for(int16_t x = 0; x < N; x++){
			int16_t soma = 0;
			soma += get_point(x-1, y+1, src_matriz, N);
			soma += get_point(x, y+1, src_matriz, N);
			soma += get_point(x+1, y+1, src_matriz, N);
			soma += get_point(x-1, y, src_matriz, N);
			soma += get_point(x+1, y, src_matriz, N);
			soma += get_point(x-1, y-1, src_matriz, N);
			soma += get_point(x, y-1, src_matriz, N);
			soma += get_point(x+1, y-1, src_matriz, N);
			
			if(src_matriz[y][x] == MORTA && soma == 3){
				dest_matriz[y][x] = VIVA;
			}
			else if((src_matriz[y][x] == VIVA && soma < 2) ||
				(src_matriz[y][x] == VIVA && soma > 3)){
				dest_matriz[y][x] = MORTA;
			}
		}
	}
	copy_matriz(dest_matriz, src_matriz, N);	
}

void input_matriz(int16_t **matriz, int16_t N){
	for(int16_t y = 0; y < N; y++){
		std::string points;
		std::cin >> points;
		for(int16_t x = 0; x < N; x++){
			int16_t point = points[x] - '0';
			matriz[y][x] = point;
		}
	}
}

void show_matriz(int16_t **matriz, int16_t N){
	for(int16_t y = 0; y < N; y++){
		for(int16_t x = 0; x < N; x++){
			std::cout << matriz[y][x];
		}
		std::cout << std::endl;
	}
}

int32_t main(void){
	int16_t N, Q;
	std::cin >> N >> Q;
	
	int16_t **matriz1 = make_matriz(N);
	int16_t **matriz2 = make_matriz(N);
	input_matriz(matriz1, N);
	copy_matriz(matriz1, matriz2, N);
	
	for(int16_t i = 0; i < Q; i++){
		update_matriz(matriz1, matriz2, N);
	}
	
	show_matriz(matriz1, N);	
	return 0;
}
