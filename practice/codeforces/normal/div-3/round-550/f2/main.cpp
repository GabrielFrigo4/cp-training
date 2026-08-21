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
#include <map>
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

bool dfs(std::map<std::pair<int, int>, std::pair<bool, bool>*> &mat, std::vector<std::vector<int>> &graph, std::vector<std::pair<bool, bool>> &nodes, int ind) {
	for (auto node : graph[ind]) {
		switch (std::get<0>(nodes[node])) {
			case false:
				std::get<1>(nodes[node]) = !std::get<1>(nodes[ind]);
				break;
			case true:
				if (std::get<1>(nodes[node]) == std::get<1>(nodes[ind])) return false;
				break;
		}

		const int min = std::min(node, ind);
		const int max = std::max(node, ind);
		std::get<1>(*mat[{ min, max }]) = std::get<1>(nodes[min]);

		if (std::get<0>(nodes[node])) continue;
		std::get<0>(nodes[node]) = true;
		if(!dfs(mat, graph, nodes, node)) {
			return false;
		}
	}
	return true;
}

void test_run(void) {
	int n, m;
	std::cin >> n >> m;

	// { invert, binary }
	std::vector<std::pair<bool, bool>> values(m, { false, false });
	// { min, max } => { invert, binary }
	std::map<std::pair<int, int>, std::pair<bool, bool>*> mat;

	// { read, state }
	std::vector<std::pair<bool, bool>> nodes(n, { false, false });

	std::vector<std::vector<int>> graph(n);
	for (int i = 0; i < m; i++){
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);

		const int min = std::min(u, v);
		const int max = std::max(u, v);
		mat[{ min, max }] = &values[i];
		values[i] = { (min != u), false };
	}

	nodes[0] = { true, true };
	if (!dfs(mat, graph, nodes, 0)) {
		std::cout << "NO" << std::endl;
		return;
	}

	std::cout << "YES" << std::endl;
	for (auto v : values) {
		std::cout << static_cast<int>((std::get<0>(v) && !std::get<1>(v)) || (!std::get<0>(v) && std::get<1>(v)));
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
