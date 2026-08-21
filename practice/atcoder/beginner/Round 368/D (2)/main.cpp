#include <bits/stdc++.h>
#include <algorithm>

#define NORMAL 0
#define MAIN 1

struct node_t {
	int64_t id;
	int64_t type;
	std::vector<node_t*> *nodes;
};

int64_t degree(node_t *node) {
	return node->nodes->size();
}

bool cmp_degree(node_t *n1, node_t *n2) {
	return degree(n1) < degree(n2);
}

void sort_nodes_degree(std::vector<node_t*> *nodes) {
	std::sort(nodes->begin(), nodes->end(), cmp_degree);
}

bool cmp_id(node_t *n1, node_t *n2) {
	return n1->id < n2->id;
}

void sort_nodes_id(std::vector<node_t*> *nodes) {
	std::sort(nodes->begin(), nodes->end(), cmp_id);
}

std::vector<node_t*>::iterator find_sort_nodes(std::vector<node_t*> *nodes, node_t *node) {
	size_t it_begin, it_end, it_ret;
	it_begin = 0;
	it_end = nodes->size();
	it_ret = (it_begin + it_end)/2;
	while (nodes->at(it_ret) != node) {
		if(nodes->at(it_ret)->id > node->id) {
			it_begin = it_ret + 1;
		}
		else {
			it_end = it_ret;
		}
	}
	return nodes->begin() + it_ret;
}

node_t *remove_node(node_t *node) {
	node_t *next = node->nodes->front();
	auto id = find_sort_nodes(next->nodes, node);
	next->nodes->erase(id);
	node->nodes->clear();
	return next;
}

void test_case()
{
	int64_t N, K;
	std::cin >> N >> K;

	if (K == 1) {
		std::cout << 1 << std::endl;
		return;
	}

	std::vector<node_t*> nodes(N);
	for (int64_t i = 0; i < N; i++) {
		nodes[i] = new node_t;
		nodes[i]->id = i + 1;
		nodes[i]->type = NORMAL;
		nodes[i]->nodes = new std::vector<node_t*>();
	}

	for (int64_t i = 0; i < N-1; i++) {
		int64_t A, B;
		std::cin >> A >> B;
		nodes[A-1]->nodes->push_back(nodes[B-1]);
		nodes[B-1]->nodes->push_back(nodes[A-1]);
	}

	for (int64_t i = 0; i < N; i++) {
		sort_nodes_id(nodes[i]->nodes);
	}

	for (int64_t i = 0; i < K; i++) {
		int64_t M;
		std::cin >> M;
		nodes[M-1]->type = MAIN;
	}

	sort_nodes_degree(&nodes);
	int64_t removed = 0;
	for (int64_t i = 0; i < N && degree(nodes[i]) == 1; i++) {
		node_t *current = nodes[i];
		if (degree(current) == 1 && current->type == NORMAL) {
			node_t *next = remove_node(current);
			removed++;

			while (degree(next) == 1 && next->type == NORMAL) {
				next = remove_node(next);
				removed++;
			}
		}
	}

	std::cout <<  N - removed << std::endl;
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
