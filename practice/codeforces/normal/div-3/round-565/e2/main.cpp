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
#include <vector>
#include <queue>
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
#define STATE_NONE (0)
#define STATE_ALL (STATE_2 | STATE_1)
#define STATE_1 (1)
#define STATE_2 (2)
#pragma endregion Define

void bfs(std::vector<std::vector<int>> &graph, std::vector<int> &states, int &s1, int &s2) {
	states[1] = STATE_1;
	s1++;

	std::queue<int> fila;
	fila.push(1);
	while (!fila.empty()) {
		int ind = fila.front();
		fila.pop();
		for (auto node : graph[ind]) {
			if (states[node] == STATE_NONE) {
				states[node] = STATE_ALL ^ states[ind];
				s1 += states[node] == STATE_1;
				s2 += states[node] == STATE_2;
				fila.push(node);
			}
		}
	}
}

void test_case(void) {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> states(n+1, STATE_NONE);
	std::vector<std::vector<int>> graph(n+1);
	for (int i = 0; i < m; i++) {
		int v, u;
		std::cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	int s1 = 0;
	int s2 = 0;
	bfs(graph, states, s1, s2);

	std::cout << std::min(s1, s2) << std::endl;
	for (int i = 1; i <= n; i++) {
		if (s1 < s2) {
			if (states[i] == STATE_1) {
				std::cout << i << " ";
			}
		}
		else {
			if (states[i] == STATE_2) {
				std::cout << i << " ";
			}
		}
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t--) {
		test_case();
	}
	return 0;
}
