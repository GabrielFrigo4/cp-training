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
#include <string>
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
#define CHAR_TO_BYTE(c) (c - 'a')
#define BYTE_TO_CHAR(b) (b + 'a')
#define LEN ('z' - 'a' + 1)
#pragma endregion Define

void test_run(void) {
	int k;
	std::cin >> k;

	std::string s, t;
	std::cin >> s >> t;

	char c = 0;
	for (int i = k - 1; i >= 0; i--) {
		const char sum = (CHAR_TO_BYTE(s[i]) + CHAR_TO_BYTE(t[i]) + c);
		const char z =  CHAR_TO_BYTE('z');
		char r = sum % LEN;

		s[i] = BYTE_TO_CHAR(r);
		c = sum / LEN;
	}

	for (int i = 0; i < k; i++) {
		const char z =  CHAR_TO_BYTE('z');
		const char sum = (CHAR_TO_BYTE(s[i]) + c * LEN);
		char r = (sum / 2) % LEN;

		s[i] = BYTE_TO_CHAR(r);
		c = sum % 2;
	}

	std::cout << s << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
