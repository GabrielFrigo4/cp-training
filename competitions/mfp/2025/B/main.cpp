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
#pragma endregion Custom

long gc;
std::vector<long> d;
std::vector<long> p;

void dsu_create(long n)
{
	gc = n;
	d.resize(n);
	p.resize(n);
	std::fill(d.begin(), d.end(), 0);
	std::iota(p.begin(), p.end(), 0);
}

long dsu_find(long v)
{
	return v == p[v] ? v : p[v] = dsu_find(p[v]);
}

void dsu_union(long a, long b)
{
	a = dsu_find(a);
	b = dsu_find(b);
	if (a == b)
	{
		return;
	}

	gc--;
	if (d[a] > d[b])
	{
		std::swap(a, b);
	}
	if (d[a] == d[b])
	{
		d[a]++;
		p[b] = a;
	}
	else
	{
		p[b] = a;
	}
}

void test_run()
{
	long N, M;
	std::cin >> N >> M;

	dsu_create(N);
	for (size_t _ = 0; _ < M; _++)
	{
		long a, b;
		std::cin >> a >> b;
		a--, b--;
		dsu_union(a, b);
	}

	long ns = gc - 1;
	long ds = (M + ns) - (N - 1);
	if (ns == 0 && ds == 0)
	{
		std::cout << "BOM" << std::endl;
	}
	else
	{
		std::cout << "RUIM " << ds << " " << ns << std::endl;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
