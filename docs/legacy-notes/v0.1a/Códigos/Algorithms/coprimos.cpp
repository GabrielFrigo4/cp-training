#include <bits/stdc++.h>

#pragma region EXTERN
int64_t mdc(const int64_t a, const int64_t b) {
	const int64_t max = std::max(a, b);
	const int64_t min = std::min(a, b);
	const int64_t rest = max % min;
	if (rest == 0)
		return min;
	return mdc(min, rest);
}
#pragma endregion EXTERN

#pragma region CODE
bool coprimos(const int64_t a, const int64_t b) {
	if(mdc(a, b) == 1)
		return true;
	return false;
}

std::vector<int64_t> coprimos_n(const int64_t n) {
	std::vector<int64_t> cop;
	for (int64_t i = 1; i < n; i++)
		if (coprimos(n, i))
			cop.push_back(i);
	return cop;
}

int64_t phi1(const int64_t n) {
	int64_t total = 0;
	for (int64_t i = 1; i < n; i++)
		if (coprimos(n, i))
			total++;
	return total;
}

int64_t phi2(int64_t n) {
	int64_t total = n;
	for (int64_t i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			total -= total / i;
		}
	}
	if (n > 1)
		total -= total / n;
	return total;
}

std::vector<int64_t> phi_n1(const int64_t n) {
	std::vector<int64_t> ph { 0, 1 };
	ph.resize(n);
	for (int64_t i = 2; i < n; i++)
		ph[i] = i - 1;
	for (int64_t i = 2; i < n; i++)
		for (int64_t j = 2 * i; j < n; j += i)
			ph[j] -= ph[i];
	return ph;
}

std::vector<int64_t> phi_n2(const int64_t n) {
	std::vector<int64_t> ph(n);
	for (int64_t i = 0; i < n; i++)
		ph[i] = i;
	for (int64_t i = 2; i < n; i++)
		if (ph[i] == i)
			for (int64_t e = i; e < n; e += i)
				ph[e] -= ph[e] / i;
	return ph;
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
#pragma endregion UTILS

#pragma region TEST
int main(void) {
    std::cout << "coprimos = " << coprimos(10, 4) << std::endl;
	std::cout << "coprimos = " << coprimos(10, 5) << std::endl;
	std::cout << "coprimos = " << coprimos(7, 5) << std::endl;
	std::cout << "coprimos = " << coprimos(35, 6) << std::endl;

	std::cout << "phi1(15) = " << phi1(15);
	std::cout << "; phi2(15) = " << phi2(15);
	std::cout << "; coprimos_n(15) = ";
	print_vector(coprimos_n(15));

	std::cout << "phi1(35) = " << phi1(35);
	std::cout << "; phi2(35) = " << phi2(35);
	std::cout << "; coprimos_n(35) = ";
	print_vector(coprimos_n(35));

	std::cout << "phi1(12) = " << phi1(12);
	std::cout << "; phi2(12) = " << phi2(12);
	std::cout << "; coprimos_n(12) = ";
	print_vector(coprimos_n(12));

	std::cout << "phi1(24) = " << phi1(24);
	std::cout << "; phi2(24) = " << phi2(24);
	std::cout << "; coprimos_n(24) = ";
	print_vector(coprimos_n(24));

	std::cout << "phi1(36) = " << phi1(36);
	std::cout << "; phi2(36) = " << phi2(36);
	std::cout << "; coprimos_n(36) = ";
	print_vector(coprimos_n(36));

	std::cout << "phi1(48) = " << phi1(48);
	std::cout << "; phi2(48 = " << phi2(48);
	std::cout << "; coprimos_n(48) = ";
	print_vector(coprimos_n(48));

	std::cout << "phi1(60) = " << phi1(60);
	std::cout << "; phi2(60) = " << phi2(60);
	std::cout << "; coprimos_n(60) = ";
	print_vector(coprimos_n(60));

	std::cout << "phi1(84) = " << phi1(84);
	std::cout << "; phi2(84) = " << phi2(84);
	std::cout << "; coprimos_n(84) = ";
	print_vector(coprimos_n(84));

	std::cout << "phi_n1(22) = ";
	print_vector(phi_n1(22));

	std::cout << "phi_n2(22) = ";
	print_vector(phi_n2(22));
}
#pragma endregion TEST