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

#pragma region Union-Find
void uf_make(std::map<int, int> &p, std::map<int, int> &d, int e) {
	p.insert({ e, e });
	d.insert({ e, 0 });
}

int uf_find(std::map<int, int> &p, int e) {
	if (p[e] == e) {
		return e;
	}
	return p[e] = uf_find(p, p[e]);
}

void uf_union(std::map<int, int> &p, std::map<int, int> &d, int e, int j) {
	e = uf_find(p, e);
	j = uf_find(p, j);
	if (e == j) {
		return;
	}

	if (d[e] < d[j]) {
		std::swap(e, j);
	}
	d[e] += d[e] == d[j];
	p[j] = e;
}
#pragma endregion Union-Find

void test_case(void) {
	int n;
	std::cin >> n;

	std::map<int, int> eq;
	std::vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		std::cin >> l[i] >> r[i];
		if (l[i] == r[i]) {
			if (!eq.contains(l[i]))  {
				eq.insert({ l[i], 0 });
			}
			eq[l[i]]++;
		}
	}

	std::map<int, int> p, d;
	for (auto [k, _] : eq) {
		uf_make(p, d, k);
	}

	for (auto [k, _] : eq) {
		if (eq.contains(k + 1)) {
			uf_union(p, d, k, k+1);
		}
	}

	for (int i = 0; i < n; i++) {
		if (l[i] == r[i]) {
			std::cout << (eq[l[i]] > 1 ? "0" : "1");
		}
		else if (eq.contains(l[i]) && eq.contains(r[i])) {
			bool is_eq = uf_find(p, l[i]) == uf_find(p, r[i]);
			std::cout << (is_eq ? "0" : "1");
		}
		else {
			std::cout << "1";
		}
	}
	std::cout <<  std::endl;
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
