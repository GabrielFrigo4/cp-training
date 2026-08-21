#include <bits/stdc++.h>

struct node_t {
	int64_t index;
	node_t *up_node;
	std::vector<node_t*> sub_nodes;
};

bool cmp(node_t &n1, node_t &n2) {
	return n1.index < n2.index;
}

int64_t query1(std::vector<node_t> &nodes, const int64_t v, const int64_t k) {
	node_t *node_k_up = &nodes[v];
	for (int64_t i = 0; i < k; i++) {
		node_k_up = nodes[node_k_up->index].up_node;
	}
	return node_k_up->index;
}

void query2(std::vector<node_t> &nodes, const int64_t v) {
	node_t *current_node = &nodes[v];
	std::vector<node_t*> change_nodes = current_node->sub_nodes;
	
	std::size_t i = 0;
	while (i < change_nodes.size()) {
		node_t *change_node = change_nodes[i];
		for (std::size_t e = 0; e < change_node->sub_nodes.size(); e++) {
			node_t *sub_node = change_node->sub_nodes[e];
			change_nodes.push_back(sub_node);
						
			sub_node->up_node = current_node;
			current_node->sub_nodes.push_back(sub_node);
		}
		change_node->sub_nodes.clear();
		i++;
	}
}

int main(void) {
	int64_t N;
	std::cin >> N;
	
	std::vector<node_t> nodes(N+1);
	for (std::size_t i = 0; i < N; i++) {
		nodes[i+1].index = i+1;
		nodes[i+1].up_node = nullptr;
		nodes[i+1].sub_nodes = std::vector<node_t*>();
	}

	std::vector<int64_t> P(N+1);
	for (std::size_t i = 0; i < N-1; i++) {
		std::cin >> P[i+2];
		nodes[i+2].up_node = &nodes[P[i+2]];
		nodes[P[i+2]].sub_nodes.push_back(&nodes[i+2]);
	}
	
	int64_t Q;
	std::cin >> Q;
	
	for (int64_t i = 0; i < Q; i++) {
		int64_t q_type, v, k;
		std::cin >> q_type;
		
		switch (q_type) {
			case 1:
				std::cin >> v >> k;
				std::cout << query1(nodes, v, k) << std::endl;
				break;
			case 2:
				std::cin >> v;
				/*
				for (node_t node : nodes) {
					int64_t up_index = 0;
					if (node.up_node != nullptr) {
						up_index = node.up_node->index;
					}
					std::cout << "{ index = " << node.index << ", up_node = " << up_index << ", sub_nodes = { ";
					for (node_t *sub_node : node.sub_nodes) {
						std::cout << sub_node->index << " ";
					} 
					std::cout << "} }" << std::endl;
				}
				*/
				query2(nodes, v);
				/*
				for (node_t node : nodes) {
					int64_t up_index = 0;
					if (node.up_node != nullptr) {
						up_index = node.up_node->index;
					}
					std::cout << "{ index = " << node.index << ", up_node = " << up_index << ", sub_nodes = { ";
					for (node_t *sub_node : node.sub_nodes) {
						std::cout << sub_node->index << " ";
					} 
					std::cout << "} }" << std::endl;
				}
				*/
				break;
		}		
	}
	
	return 0;
}
