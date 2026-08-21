#include <bits/stdc++.h>

int32_t main(){
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	int32_t S, T;
	std::cin >> S >> T;

	int8_t **STz = (int8_t **)malloc(sizeof(int8_t *) * S);
	for(int32_t y = 0; y < S; y++){
		STz[y] = (int8_t *)malloc(sizeof(int8_t) * S);
		for(int32_t x = 0; x < S; x++){
			STz[y][x] = 0;
		}
	}

	for(int32_t i = 0; i < T; i++){
		int32_t X, Y;
		std::cin >> X >> Y;
		STz[X-1][Y-1] = 1;
		STz[Y-1][X-1] = 1;
	}

	int32_t P, validos;
	std::cin >> P;
	for(int32_t i = 0; i < P; i++){
		int32_t N, C0 = -1, C1 = -1;
		std::cin >> N;
		for(int32_t e = 0; e < N; e++){
			if(C1 == -1){
				std::cin >> C1;
			}
			else{
				C0 = C1;
				std::cin >> C1;

				if(STz[C0-1][C1-1] == 0){
					validos--;
					break;
				}
			}
		}
		validos++;
	}

	for(int32_t y = 0; y < S; y++){
		free(STz[y]);
	}
	free(STz);

	std::cout << validos << std::endl;
	return 0;
}
