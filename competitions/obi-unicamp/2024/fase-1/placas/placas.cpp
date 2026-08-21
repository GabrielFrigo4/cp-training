#include <bits/stdc++.h>
#define ANTIGO 8
#define NOVO 7

bool is_letra_maiuscula(char c){
	return c >= 'A' && c <= 'Z';
}

bool is_digito(char c){
	return c >= '0' && c <= '9';
}

bool is_hifen(char c){
	return c == '-';
}

int32_t main(void){
	std::string placa;
	std::cin >> placa;
	
	if(placa.size() != ANTIGO && placa.size() != NOVO){
		std::cout << 0 << std::endl;	
	}
	else if(placa.size() == ANTIGO){
		bool resultado = true;
		resultado *= is_letra_maiuscula(placa[0]);
		resultado *= is_letra_maiuscula(placa[1]);
		resultado *= is_letra_maiuscula(placa[2]);
		resultado *= is_hifen(placa[3]);
		resultado *= is_digito(placa[4]);
		resultado *= is_digito(placa[5]);
		resultado *= is_digito(placa[6]);
		resultado *= is_digito(placa[7]);
		if(resultado){
			std::cout << 1 << std::endl;
		}
		else{
			std::cout << 0 << std::endl;
		}
	}
	else if(placa.size() == NOVO){
		bool resultado = true;
		resultado *= is_letra_maiuscula(placa[0]);
		resultado *= is_letra_maiuscula(placa[1]);
		resultado *= is_letra_maiuscula(placa[2]);
		resultado *= is_digito(placa[3]);
		resultado *= is_letra_maiuscula(placa[4]);
		resultado *= is_digito(placa[5]);
		resultado *= is_digito(placa[6]);
		if(resultado){
			std::cout << 2 << std::endl;
		}
		else{
			std::cout << 0 << std::endl;
		}
	}
	
	return 0;
}
