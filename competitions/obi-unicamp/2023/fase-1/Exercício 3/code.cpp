#include <bits/stdc++.h>

int32_t main(){
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	int64_t A, B;
	std::cin >> A >> B;

	int64_t *Sa = (int64_t *)malloc(sizeof(int64_t) * A);
	for(int64_t x = 0; x < A; x++){
		std::cin >> Sa[x];
	}

	int64_t *Sb = (int64_t *)malloc(sizeof(int64_t) * B);
	for(int64_t x = 0; x < B; x++){
		std::cin >> Sb[x];
	}

	bool sucess = false;
	int64_t b = 0;
	for(int64_t a = 0; a < A; a++){
		if(Sa[a] == Sb[b]){
			b++;
		}
		if(b == B){
			sucess = true;
			break;
		}
	}

	free(Sa);
	free(Sb);

	if(sucess){
		std::cout << "S" << std::endl;
	}
	else{
		std::cout << "N" << std::endl;
	}
	return 0;
}
