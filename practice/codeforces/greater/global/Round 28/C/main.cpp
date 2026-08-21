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
#pragma endregion Define

std::string xor_str(std::string str1, std::string str2) {
	if (str1.length() < str2.length()) {
		std::swap(str1, str2);
	}

	for (int i2 = 0; i2 < str2.length(); i2++) {
		const int i1 = i2 + str1.length() - str2.length();
		if (str1[i1] == str2[i2]) {
			str1[i1] = '0';
		}
		else {
			str1[i1] = '1';
		}
	}

	return str1;
}

void test_case(void) {
	std::string bstr;
	std::cin >> bstr;

	int len = bstr.length();
	for (char c : bstr) {
		if (c == '0') {
			break;
		}
		len--;
	}
	len += len == 0;

	int l1 = 1, r1 = l1 + len - 1;
	std::string max = xor_str(bstr, bstr.substr(l1 - 1, len));
	for (int l = 1, r; (r = l + len - 1) <= bstr.length(); l++) {
		std::string tmp = xor_str(bstr, bstr.substr(l - 1, len));
		if (tmp > max) {
			max = tmp;
			l1 = l;
			r1 = r;
		}
	}

	std::cout << "1 " << bstr.length() << " " << l1 << " " << r1 << std::endl;
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
