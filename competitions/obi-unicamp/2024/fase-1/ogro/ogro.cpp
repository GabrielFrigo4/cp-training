#include <bits/stdc++.h>

int32_t main(void){
	int16_t E, D;
	std::cin >> E >> D;
	
	int16_t resposta = 0;
	if(E > D){
		resposta = E + D;
	}
	else{
		resposta = 2*(D - E);
	}
	
	std::cout << resposta << std::endl;
	return 0;
}
