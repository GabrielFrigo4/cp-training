#include <bits/stdc++.h>

#pragma region EXTERN
#define EXP2(x) (1LL << x)
#define PRIMO_MERCENE_FORMATO(x) (EXP2(x) - 1)
#pragma endregion EXTERN

#pragma region CODE
#define NUMERO_PERFEITO_FROMATO(x) ((EXP2(x-1))*PRIMO_MERCENE_FORMATO(x))

std::array<int64_t, 8> perfeito_lista = {
	NUMERO_PERFEITO_FROMATO(2),
	NUMERO_PERFEITO_FROMATO(3),
	NUMERO_PERFEITO_FROMATO(5),
	NUMERO_PERFEITO_FROMATO(7),
	NUMERO_PERFEITO_FROMATO(13),
	NUMERO_PERFEITO_FROMATO(17),
	NUMERO_PERFEITO_FROMATO(19),
	NUMERO_PERFEITO_FROMATO(31)
};

bool perfeito(const int64_t n) {
	auto it = std::lower_bound(perfeito_lista.begin(), perfeito_lista.end(), n);
	if (it == perfeito_lista.end())
		return false;
	return *it == n;
}

int64_t sigma(int64_t n) {
	int64_t total = 1;
	for (int64_t i = 2; i * i <= n; i++) {
		int e = 0;
		while (n % i == 0) {
			e++;
			n /= i;
		}
		if (e != 0) {
			int64_t sum = 0, pow = 1;
			for (; e >= 0; e--) {
				sum += pow;
				pow *= i;
			}
			total *= sum;
		}
	}
	if (n > 1) {
		total *= (1 + n);
	}
	return total;
}
#pragma endregion CODE

#pragma region TEST
int main(void) {
	std::cout << "perfeito(3) = " << perfeito(3) << std::endl;
	std::cout << "perfeito(6) = " << perfeito(6) << std::endl;
	std::cout << "perfeito(9) = " << perfeito(9) << std::endl;
	std::cout << "perfeito(28) = " << perfeito(28) << std::endl;

	std::cout << "sigma(3) = " << sigma(3) << std::endl;
	std::cout << "sigma(6) = " << sigma(6) << std::endl;
	std::cout << "sigma(9) = " << sigma(9) << std::endl;
	std::cout << "sigma(28) = " << sigma(28) << std::endl;
}
#pragma endregion TEST
