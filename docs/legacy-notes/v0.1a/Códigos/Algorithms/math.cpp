#include <bits/stdc++.h>

#pragma region CODE
int64_t mdc(const int64_t a, const int64_t b) {
	const int64_t max = std::max(a, b);
	const int64_t min = std::min(a, b);
	const int64_t rest = max % min;
	if (rest == 0)
		return min;
	return mdc(min, rest);
}

int64_t divisors_count(int64_t num) {
	int64_t total = 1;
	for (int64_t i = 2; i * i <= num; i++) {
		int64_t e = 0;
		while (num % i == 0) {
			e++;
			num /= i;
		}
		if (e != 0) {
			total *= e + 1;
		}
	}
	if (num > 1) {
		total *= 2;
	}
	return total;
}

#define EXP2(x) (1LL << x)
#pragma endregion CODE

#pragma region TEST
int main(void) {
	std::cout << "mdc(10, 4) = " << mdc(10, 4) << std::endl;
	std::cout << "mdc(10, 5) = " << mdc(10, 5) << std::endl;
	std::cout << "mdc(7, 5) = " << mdc(7, 5) << std::endl;
	std::cout << "mdc(35, 6) = " << mdc(35, 6) << std::endl;

	std::cout << "divisors_count(1) = " << divisors_count(1) << std::endl;
	std::cout << "divisors_count(2) = " << divisors_count(2) << std::endl;
	std::cout << "divisors_count(3) = " << divisors_count(3) << std::endl;
	std::cout << "divisors_count(5) = " << divisors_count(5) << std::endl;
	std::cout << "divisors_count(10) = " << divisors_count(10) << std::endl;
	std::cout << "divisors_count(20) = " << divisors_count(20) << std::endl;
	std::cout << "divisors_count(36) = " << divisors_count(36) << std::endl;

	std::cout << "EXP2(0) = " << EXP2(0) << std::endl;
	std::cout << "EXP2(1) = " << EXP2(1) << std::endl;
	std::cout << "EXP2(4) = " << EXP2(4) << std::endl;
	std::cout << "EXP2(8) = " << EXP2(8) << std::endl;
	std::cout << "EXP2(10) = " << EXP2(10) << std::endl;
}
#pragma endregion TEST
