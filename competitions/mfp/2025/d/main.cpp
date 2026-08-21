#pragma region Include
#include <algorithm>
#include <iostream>
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
#include <iomanip>
#include <array>
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
#define PI 3.14159265359
#define FINF 1e10
#pragma endregion Custom

void test_run()
{
	std::array<long, 3> R;
	std::cin >> R[0] >> R[1] >> R[2];

	long N, Q;
	std::cin >> N >> Q;

	while (Q--)
	{
		long C1, L1, C2, L2;
		std::cin >> C1 >> L1 >> C2 >> L2;
		C1--, L1--, C2--, L2--;

		double delta_l = static_cast<double>(std::min(std::abs(L1 - L2), N - std::abs(L1 - L2)));
		if (delta_l == 0)
		{
			std::cout << static_cast<double>(std::abs(R[C1] - R[C2])) << std::endl;
		}
		else
		{
			double dist = FINF;
			for (long i = 0; i < 3; i++)
			{
				double tmp = std::abs(R[C1] - R[i]) + std::abs(R[C2] - R[i]);
				tmp += 2 * PI * (delta_l / N) * R[i];
				dist = std::min(dist, tmp);
			}
			std::cout << dist << std::endl;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	std::cout << std::fixed << std::setprecision(10);
	test_run();
	return 0;
}
