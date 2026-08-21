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
#pragma endregion Define

bool dfs(std::set<std::pair<int, int>> &mat, std::vector<std::vector<int>> &graph, std::vector<int> &nodes, int ind) {
	for (auto node : graph[ind]) {
		bool call = false;
		switch (nodes[node]) {
			case -1:
				nodes[node] = !nodes[ind];
				call = true;
				break;
			default:
				if (nodes[node] == nodes[ind]) return false;
				break;
		}

		if (nodes[node] == true) {
			mat.insert({node, ind});
		}
		else {
			mat.insert({ind, node});
		}

		if (!call) continue;
		if(!dfs(mat, graph, nodes, node)) {
			return false;
		}
	}
	return true;
}

void test_run(void) {
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> nodes(n, -1);
	std::vector<std::pair<int, int>> edges(m);
	std::vector<std::vector<int>> graph(n);
	std::set<std::pair<int, int>> mat;
	for (int i = 0; i < m; i++){
		int u, v;
		std::cin >> u >> v;
		edges[i] = {--u, --v};
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	nodes[0] = false;
	if (!dfs(mat, graph, nodes, 0)) {
		std::cout << "NO" << std::endl;
		return;
	}

	std::cout << "YES" << std::endl;
	for (auto e : edges) {
		if (mat.contains(e)) {
			std::cout << "0";
		}
		else {
			std::cout << "1";
		}
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
