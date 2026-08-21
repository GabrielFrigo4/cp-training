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
#define MOD(v, m) ((v + m) % m)
#pragma endregion Custom

void test_case(std::string &w, std::vector<std::string> &m, long s) {
	while (s--) {
		std::string _w = w;
		for (int i = 0; i < w.length(); i++) {
			for (auto &_m : m) {
				if (w[MOD(i - 2, w.length())] == _m[0] &&
					w[MOD(i, w.length())] == _m[1] &&
					w[MOD(i + 1, w.length())] == _m[2]) {
					_w[MOD(i, w.length())] = _m[3];
				}
			}
		}
		w = _w;
	}

	int mod = 0;
	for (int i = 0; i < w.length(); i++) {
		for (int j = 0; j < w.length(); j++) {
			if (w[MOD(j + mod, w.length())] < w[MOD(j + i, w.length())]) {
				break;
			}
			if (w[MOD(j + mod, w.length())] > w[MOD(j + i, w.length())]) {
				mod = i;
				break;
			}
		}
	}

	for (int i = 0; i < w.length(); i++) {
		std::cout << w[MOD(i + mod, w.length())];
	}
	std::cout << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long n;
	std::cin >> n;

	std::string w;
	std::cin >> w;

	std::vector<std::string> m;
	long T = 8;
	while (T--) {
		std::string str;
		std::cin >> str;
		m.push_back(str);
	}

	long s;
	std::cin >> s;
	test_case(w, m, s);
	return 0;
}
