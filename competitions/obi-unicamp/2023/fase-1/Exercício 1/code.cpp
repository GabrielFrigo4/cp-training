#include <bits/stdc++.h>

int32_t main(){
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	int64_t V, A, F, P;
	std::cin >> V >> A >> F >> P;

	std::vector<int64_t> contas {A, F, P};
	std::sort(contas.begin(), contas.end());

	int total = 0;
	for(; total < 3; total++){
		V -= contas[total];
		if(V < 0){
			break;
		}
	}

	std::cout << total << std::endl;
	return 0;
}
