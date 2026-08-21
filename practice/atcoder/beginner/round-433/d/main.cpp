#pragma region Include
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <numbers>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Include

#pragma region Library
#include <vector>
#include <array>
#include <map>
#pragma endregion Library

#pragma region Types
#define byte uint8_t
#define short int16_t
#define int int32_t
#define long int64_t
typedef int8_t sbyte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;
#pragma endregion Types

#pragma region Constant
#undef LONG_MIN
#undef LONG_MAX
#undef ULONG_MAX
#define SBYTE_MIN SCHAR_MIN
#define SBYTE_MAX SCHAR_MAX
#define BYTE_MAX UCHAR_MAX
#define LONG_MIN LLONG_MIN
#define LONG_MAX LLONG_MAX
#define ULONG_MAX ULLONG_MAX
#define INF_MIN -0x3f3f3f3f3f3f3f3fLL
#define INF_MAX 0x3f3f3f3f3f3f3f3fLL
#define INF(type) ((1LL << (sizeof(type) * 8 - 2)) - 1)
#pragma endregion Constant

#pragma region Custom
#define MOD_M(x) (((x) % M + M) % M)
#define SIZE 10
#pragma endregion Custom

ulong get_k(long n)
{
	ulong k = 0;
	while (n > 0) {
		n /= 10;
		k++;
	}
	return k;
}

ulong exp_10(long k)
{
	ulong exp = 1;
	while (k--) {
		exp *= 10;
	}
	return exp;
}

void test_run()
{
	long N, M;
	std::cin >> N >> M;

	std::vector<long> A(N);
	std::array<std::map<long, long>, SIZE + 1> J;
	for (long &a : A) {
		std::cin >> a;
		const long k = get_k(a);
		const long m = MOD_M(-a);
		if (!J[k].contains(m)) {
			J[k][m] = 0;
		}
		J[k][m]++;
	}

	long count = 0;
	for (long a : A) {
		for (long k = 1; k < SIZE + 1; k++) {
			const long m = MOD_M(exp_10(k) * static_cast<ulong>(a));
			if (J[k].contains(m)) {
				count += J[k][m];
			}
		}
	}
	std::cout << count << std::endl;
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
