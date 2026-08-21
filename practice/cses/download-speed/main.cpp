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
#include <queue>
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

std::vector<std::vector<long>> capacity;
std::vector<std::vector<long>> adj;

long bfs(long s, long t, std::vector<long>& parent)
{
	std::fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	std::queue<std::pair<long, long>> q;
	q.push({s, INF(long)});

	while (!q.empty())
	{
		long cur = q.front().first;
		long flow = q.front().second;
		q.pop();

		for (long next : adj[cur])
		{
			if (parent[next] == -1 && capacity[cur][next])
			{
				parent[next] = cur;
				long new_flow = std::min(flow, capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push({next, new_flow});
			}
		}
	}

	return 0;
}

long maxflow(long s, long t, long n)
{
	long flow = 0;
	std::vector<long> parent(n);
	long new_flow;

	while (new_flow = bfs(s, t, parent))
	{
		flow += new_flow;
		long cur = t;
		while (cur != s)
		{
			long prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}

	return flow;
}

void test_run()
{
	capacity.clear();
	adj.clear();

	long n, m;
	std::cin >> n >> m;
	capacity.resize(n);
	for (size_t i = 0; i < n; i++)
	{
		capacity[i].resize(n);
	}
	adj.resize(n);

	for (size_t i = 0; i < m; i++)
	{
		long a, b, c;
		std::cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		capacity[a][b] += c;
	}

	std::cout << maxflow(0, n - 1, n) << std::endl;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
