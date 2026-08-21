#include <bits/stdc++.h>

int32_t main(void){
	int16_t N, K;
	std::cin >> N >> K;
	
	std::vector<int16_t> notas;
	for(int16_t i = 0; i < N; i++){
		int16_t nota;
		std::cin >> nota;
		notas.push_back(nota);
	}
	std::sort(notas.begin(), notas.end());
	
	int16_t nota_corte = notas[N-K];
	std::cout << nota_corte << std::endl;
	return 0;
}
