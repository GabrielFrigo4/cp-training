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
#pragma endregion Custom

std::string apply_jmp(std::string &bs, std::vector<int> &jmp) {
	std::string bs2(bs.length(), '0');
	for (int i = 0; i < bs.length(); i++) {
		if (i + jmp[i] >= bs2.length() || i + jmp[i] < 0) {
			continue;
		}
		if (bs[i] == '1') {
			bs2[i + jmp[i]] = bs[i];
		}
	}
	return bs2;
}

void test_case(void) {
	int n;
	long k;
	std::cin >> n >> k;

	std::string bs;
	std::cin >> bs;

	int tmp_sz = 0;
	int tmp_jmp = 0;
	std::vector<int> jmp(n);
	for (int i = 0; i < jmp.size(); i++) {
		if (bs[i] == '0') {
			k -= tmp_sz;
			tmp_jmp++;
		}
		else {
			tmp_sz++;
		}

		if (k <= 0) {
			jmp[i] = tmp_jmp;
			tmp_jmp = 0;
			break;
		}

		if (i > 0 && bs[i] == '1' && bs[i - 1 == '0']) {
			jmp[i - 1] = tmp_jmp;
			tmp_jmp = 0;
		}
	}
	if (tmp_jmp > 0) {
		jmp.back() = tmp_jmp;
	}

	for (int i = jmp.size() - 2; i > -1; i--) {
		jmp[i] += jmp[i + 1];
	}

	std::string bs2 = apply_jmp(bs, jmp);
	for (int i = 0; (i < bs2.length()) && (k < 0); i++) {
		if (bs2[i] == '1') {
			std::swap(bs2[i - 1], bs2[i]);
			k++;
		}
	}

	std::cout << bs2 << std::endl;
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
