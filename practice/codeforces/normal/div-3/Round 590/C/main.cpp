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
#include <array>
#include <string>
#include <map>
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

void test_case(void) {
	int n;
	std::cin >> n;

	std::array<std::string, 2> pipes;
	for (auto &pipe : pipes) {
		std::cin >> pipe;
	}

	std::map<char, std::pair<int, int>> paths = {
		{ '2', { 1, 0 } },
		{ '3', { 1, 0 } },
		{ '4', { 0, 1 } },
		{ '5', { 0, -1 } },
		{ '6', { 1, 0 } },
	};

	int x = -1;
	int y = 0;
	char pipe = '2';
	while (x < n) {
		int nx = x + std::get<0>(paths[pipe]);
		int ny = y + std::get<1>(paths[pipe]);

		if (nx == n) {
			x = nx;
			y = ny;
			break;
		}

		if (ny != y) {
			switch (pipes[ny][nx]) {
				case '1'...'2':
					std::cout << "NO" << std::endl;
					return;
					break;
				case '3'...'6':
					pipe = (ny == 0 ? '3' : '6');
					break;
			}
		}
		else {
			switch (pipes[ny][nx]) {
				case '1'...'2':
					pipe = '2';
					break;
				case '3'...'6':
					pipe = (ny == 0 ? '4' : '5');
					break;
			}
		}

		x = nx;
		y = ny;
	}

	std::cout << (y == 1 ? "YES" : "NO") << std::endl;
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
