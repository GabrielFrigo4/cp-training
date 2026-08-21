#include <bits/stdc++.h>
#include <algorithm>

#define NONE 0
#define WAIT 1
#define OK 2
#define OFF 3

struct node_t {
	int64_t id;
	bool is_main;
};

struct edge_t {
	node_t *a, *b;
	int8_t type;
};

node_t *get_other_node(edge_t edge, node_t *node) {
	return reinterpret_cast<node_t*> (
		reinterpret_cast<std::uintptr_t>(edge.a) ^
		reinterpret_cast<std::uintptr_t>(edge.b) ^
		reinterpret_cast<std::uintptr_t>(node)
		);
}

int8_t not_used_edges(std::vector<std::vector<edge_t*>> &matriz, node_t *current_node, int64_t *not_used) {
	int8_t main_type = OFF;
	if (current_node->is_main) {
		main_type = OK;
	}

	for (int64_t i = 0; i < matriz[current_node->id-1].size(); i++) {
		edge_t &edge = *(matriz[current_node->id-1][i]);
		if (edge.type == NONE) {	
			edge.type = WAIT;
			node_t *new_node = get_other_node(edge, current_node);
			int8_t type = not_used_edges(matriz, new_node, not_used);
			edge.type = type;
			if (type == OK) {
				main_type = OK;
			}
		}
	}

	if (main_type == OFF) {
		(*not_used)++;
	}
	return main_type;
}

void test_case()
{
	int64_t N, K;
	std::cin >> N >> K;

	if (K == 1) {
		std::cout << 1 << std::endl;
		return;
	}

	std::vector<node_t> nodes(N);
	for (int64_t i = 0; i < nodes.size(); i++) {
		nodes[i].id = i+1;
		nodes[i].is_main = false;
	}

	std::vector<edge_t> edges(N-1);
	for (auto &edge : edges) {
		int64_t id_a, id_b;
		std::cin >> id_a >> id_b;
		edge.a = &nodes[id_a-1];
		edge.b = &nodes[id_b-1];
		edge.type = NONE;
	}

	std::vector<node_t*> V(K);
	for (int64_t i = 0; i < K; i++) {
		int64_t v;
		std::cin >> v;
		nodes[v-1].is_main = true;
		V[i] = &nodes[v-1];
	}

	std::vector<std::vector<edge_t*>> matriz(N);
	for (int64_t i = 0; i < N; i++) {
		std::vector<edge_t*> line;
		matriz[i] = line;
	}
	for (auto &edge : edges) {
		matriz[edge.a->id-1].push_back(&edge);
		matriz[edge.b->id-1].push_back(&edge);
	}

	int64_t not_used = 0;
	for (node_t *v : V) {
		not_used_edges(matriz, v, &not_used);
		break;
	}

	std::cout << N - not_used << std::endl;
	return;
}

int32_t main(void)
{
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
