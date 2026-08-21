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
#define MAXSUM (4000)
#define OFFSET (MAXSUM)
#define SIZE (2 * MAXSUM + 1)
//#define DEBUG
#pragma endregion Custom

void test_case()
{
	long N;
	std::cin >> N;

	std::vector<long> a(N);
	for (auto &_a : a) {
		std::cin >> _a;
	}

	long M[5][SIZE]{};
	M[0][OFFSET] = 1;
	for (auto _a : a) {
		for (long k = 3; k >= 0; k--) {
			for (long s = 0; s < SIZE; s++) {
				if (M[k][s] == 0) {
					continue;
				}
				int next = s + _a;
				if (next >= 0 && next < SIZE) {
					M[k + 1][next] += M[k][s];
				}
			}
		}
	}

#ifdef DEBUG
	const long range = 20;
	for (long y = 1; y <= 4; y++) {
		for (long x = OFFSET - range; x <= OFFSET + range; x++) {
			std::cout << M[y][x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	long Q;
	std::cin >> Q;
	while (Q--) {
		long q;
		std::cin >> q;
		std::cout << M[4][q + OFFSET] << std::endl;
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t = 1;
	//std::cin >> t;

	while (t--)
	{
		test_case();
	}
	return 0;
}
