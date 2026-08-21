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
#include <string>
#include <set>
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
#pragma endregion Constant

#pragma region Custom
#pragma endregion Custom

std::string ans;
void dfs(const std::vector<std::vector<int>> &tree, const std::vector<int> &a, const int curr, const int last) {
	std::set<int> count = { a[curr] };
	for (auto node : tree[curr]) {
		if (count.contains(a[node])) {
			ans[a[node]] = '1';
		}
		else {
			count.insert(a[node]);
		}
	}

	for (auto node : tree[curr]) {
		if (node == last) {
			continue;
		}
		dfs(tree, a, node, curr);
	}
}

void test_case(void) {
	int n;
	std::cin >> n;
	ans = std::string(n, '0');

	std::vector<int> a(n);
	for (auto &_a : a) {
		std::cin >> _a;
		_a--;
	}

	std::vector<std::vector<int>> tree(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		std::cin >> u >> v;
		u--, v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(tree, a, 0, -1);
	std::cout << ans << std::endl;
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