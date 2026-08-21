#pragma region Default-Include
#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Default-Include

#pragma region Include
#include <array>
#include <set>
#pragma endregion Include

#pragma region Default-Define
#define sbyte int8_t
#define short int16_t
#define int int32_t
#define long int64_t
#define byte uint8_t
#define ushort uint16_t
#define uint uint32_t
#define ulong uint64_t
#pragma endregion Default-Define

#pragma region Define
#define MAX_B 2750131
#define MAX_POS 199999
#pragma endregion Define

std::array<int, MAX_POS + 1> primes;
std::array<int, MAX_B + 1> sieve;

void find_primes()
{
	primes[0] = 1;
	sieve.fill(-1);

	int p = 0;
	for (int i = 2; i <= MAX_B; i++)
	{
		if (sieve[i] != -1)
			continue;
		sieve[i] = ++p;
		primes[p] = i;
		if ((long)i * i > MAX_B)
			continue;
		for (int s = i * i; s <= MAX_B; s += i)
		{
			sieve[s] = 0;
		}
	}
}

void test_run(void)
{
	find_primes();

	int n;
	std::cin >> n;

	std::multiset<int> b;
	for (int i = 0; i < 2 * n; i++)
	{
		int _b;
		std::cin >> _b;
		b.insert(_b);
	}

	for (auto itb = b.rbegin(); itb != b.rend(); std::advance(itb, 1))
	{
		auto _b = *itb;

		if (sieve[_b] != 0)
			continue;
		for (auto p : primes)
		{
			if (p == 1)
				continue;
			if (_b % p == 0)
			{
				b.erase(b.find(_b / p));
				break;
			}
		}
	}

	for (auto itb = b.begin(); itb != b.end(); std::advance(itb, 1))
	{
		auto _b = *itb;

		if (sieve[_b] == 0)
			continue;
		b.erase(b.find(primes[_b]));
	}

	for (auto _b : b)
	{
		std::cout << _b << " ";
	}
	std::cout << std::endl;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
