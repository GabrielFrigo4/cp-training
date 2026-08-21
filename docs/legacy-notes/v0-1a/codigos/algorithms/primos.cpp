#include <bits/stdc++.h>

#pragma region EXTERN
#define EXP2(x) (1LL << x)
#pragma endregion EXTERN

#pragma region CODE
bool primo(const int64_t n) {
	if(n == 1)
		return false;
	else if (n < 4)
		return true;
	else if (n % 2 == 0)
		return false;
	else if (n < 9)
		return true;
	else if (n % 3 == 0)
		return false;
	else {
		int64_t r = std::floor(std::sqrt(n));
		int64_t f = 5;
		while (f <= r) {
			if (n % f == 0)
				return false;
			if (n % (f+2) == 0)
				return false;
			f += 6;
		}
		return true;
	}
}

std::vector<std::pair<int64_t, int64_t>> fatores_primos(int64_t n) {
	std::vector<std::pair<int64_t, int64_t>> prim;
	if (n % 2 == 0) {
		std::pair<int64_t, int64_t> p2(2, 0);
		while (n % 2 == 0) {
			n /= 2;
			p2.second++;
		}
		prim.push_back(p2);
	}
	for (int64_t fator = 3; n > 1 && fator <= std::sqrt(n); fator += 2) {
		if (n % fator == 0) {
			std::pair<int64_t, int64_t> pf(fator, 0);
			while (n % fator == 0) {
				n /= fator;
				pf.second++;
			}
			prim.push_back(pf);
		}
	}
	if (n > 1)
		prim.push_back(std::pair<int64_t, int64_t>(n, 1));
	return prim;
}

std::vector<int64_t> primos_n1(const int64_t n) {
	std::vector<int64_t> prim;
	if (n > 2)
		prim.push_back(2);
	for (int64_t cand = 3; cand < n; cand += 2)
		if (primo(cand))
			prim.push_back(cand);
	return prim;
}

std::vector<int64_t> primos_n2(const int64_t n) {
	std::vector<int64_t> prim;
	prim.reserve(n/2);
	if (n > 2)
		prim.push_back(2);
	for (int64_t i = 3; i < n; i += 2)
		prim.push_back(i);
	for (int64_t i = 1; i < prim.size(); i++) {
		if (prim[i] * prim[i] >= n)
			break;
		std::vector<int64_t> tmp(prim.begin(), prim.begin() + i + 1);
		for (int64_t e = i + 1; e < prim.size(); e++)
			if (prim[e] % prim[i] != 0)
				tmp.push_back(prim[e]);
		prim = tmp;
	}
	return prim;
}

#define PRIMO_MERCENE_FORMATO(x) (EXP2(x) - 1)

std::array<int64_t, 9> exponente_primo_mercene_lista = { 2, 3, 5, 7, 13, 17, 19, 31, 61 };

std::array<int64_t, 9> primo_mercene_lista = {
	PRIMO_MERCENE_FORMATO(2),
	PRIMO_MERCENE_FORMATO(3),
	PRIMO_MERCENE_FORMATO(5),
	PRIMO_MERCENE_FORMATO(7),
	PRIMO_MERCENE_FORMATO(13),
	PRIMO_MERCENE_FORMATO(17),
	PRIMO_MERCENE_FORMATO(19),
	PRIMO_MERCENE_FORMATO(31),
	PRIMO_MERCENE_FORMATO(61)
};

bool primo_mercene(const int64_t n) {
	auto it = std::lower_bound(primo_mercene_lista.begin(), primo_mercene_lista.end(), n);
	if (it == primo_mercene_lista.end())
		return false;
	return *it == n;
}
#pragma endregion CODE

#pragma region UTILS
void print_vector(std::vector<int64_t> vec)
{
	std::cout << "{ ";
	for (int64_t e : vec)
		std::cout << e << " ";
	std::cout << "}" << std::endl;
}

void print_vector_pair(std::vector<std::pair<int64_t, int64_t>> vec)
{
	std::cout << "{ ";
	for (std::pair<int64_t, int64_t> e : vec)
		std::cout << "[" << e.first << ", " << e.second << "] ";
	std::cout << "}" << std::endl;
}
#pragma endregion UTILS

#pragma region TEST
int main(void) {
	for (int64_t i = 1; i < 38; i++) {
		std::cout << "primo(" << i << ") = " << primo(i) << std::endl;
	}

	std::cout << "fatores_primos(2*19) = ";
	print_vector_pair(fatores_primos(2*19));
	std::cout << "fatores_primos(2*2*19) = ";
	print_vector_pair(fatores_primos(2*2*19));
	std::cout << "fatores_primos(2*2*3*3*19) = ";
	print_vector_pair(fatores_primos(2*2*3*3*19));
	std::cout << "fatores_primos(2*2*3*3*5*5*5*5*5*5*19*19*19) = ";
	print_vector_pair(fatores_primos(2LL*2LL*3LL*3LL*5LL*5LL*5LL*5LL*5LL*5LL*19LL*19LL*19LL));

	std::cout << "primos_n1(2) = ";
	print_vector(primos_n1(2));
	std::cout << "primos_n2(2) = ";
	print_vector(primos_n2(2));
	std::cout << "primos_n1(3) = ";
	print_vector(primos_n1(3));
	std::cout << "primos_n2(3) = ";
	print_vector(primos_n2(3));
	std::cout << "primos_n1(5) = ";
	print_vector(primos_n1(5));
	std::cout << "primos_n2(5) = ";
	print_vector(primos_n2(5));
	std::cout << "primos_n1(121) = ";
	print_vector(primos_n1(121));
	std::cout << "primos_n2(121) = ";
	print_vector(primos_n2(121));
	std::cout << "primos_n1(1 << 8) = ";
	print_vector(primos_n1(1 << 8));
	std::cout << "primos_n2(1 << 8) = ";
	print_vector(primos_n2(1 << 8));
	std::cout << "primos_n1(1 << 12) = ";
	print_vector(primos_n1(1 << 12));
	std::cout << "primos_n2(1 << 12) = ";
	print_vector(primos_n2(1 << 12));
	std::cout << "primos_n2(1 << 16) = ";
	print_vector(primos_n2(1 << 16));
	std::cout << "primos_n2(1 << 16) = ";
	print_vector(primos_n2(1 << 16));

	std::cout << "primo_mercene(1) = " << primo_mercene(1) << std::endl;
	std::cout << "primo_mercene(2) = " << primo_mercene(2) << std::endl;
	std::cout << "primo_mercene(3) = " << primo_mercene(3) << std::endl;
	std::cout << "primo_mercene(7) = " << primo_mercene(7) << std::endl;
	std::cout << "primo_mercene(1L << 62) = " << primo_mercene(EXP2(62)) << std::endl;
}
#pragma endregion TEST
