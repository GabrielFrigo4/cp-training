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
#pragma endregion Constant

#pragma region Custom
#pragma endregion Custom

std::vector<int> p;
std::vector<int> s;

void dsu_make(const int n) {
	p.resize(n);
	s.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		s[i] = 1;
	}
}

int dsu_find(const int x) {
	if (p[x] == x) {
		return x;
	}
	return p[x] = dsu_find(p[x]);
}

void dsu_union(int x, int y) {
	x = dsu_find(x);
	y = dsu_find(y);

	if (x == y) {
		return;
	}

	if (s[x] < s[y]) {
		std::swap(x, y);
	}

	s[x] += s[y];
	p[y] = x;
}

void test_case(void) {
	int n;
	std::cin >> n;
	dsu_make(n);

	std::vector<int> p(n);
	for (auto &_p : p) {
		std::cin >> _p;
		_p--;
	}

	for (int i = 0; i < n; i++) {
		dsu_union(i, p[i]);
	}

	for (int i = 0; i < n; i++) {
		std::cout << s[dsu_find(i)] << " ";
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long q;
	std::cin >> q;

	while (q--) {
		test_case();
	}
	return 0;
}
