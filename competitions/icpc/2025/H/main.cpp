#pragma region Include
#include <algorithm>
#include <iostream>
#include <iomanip>
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
#include <bitset>
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
#define INF_MIN -0x3f3f3f3f3f3f3f3fLL
#define INF_MAX 0x3f3f3f3f3f3f3f3fLL
#define INF(type) ((1LL << (sizeof(type) * 8 - 2)) - 1)
#pragma endregion Constant

#pragma region Custom
//#define DEBUG
#pragma endregion Custom

ulong rotate_bits(ulong bits) {
	ulong rbits = 0ULL;
	while (bits > 0ULL) {
		long bit = (bits & 1ULL);
		bits >>= 1ULL;
		rbits <<= 1ULL;
		rbits += bit;
	}
	return rbits;
}

ulong next_palindrome(ulong bits, ulong index) {
	do {
		index++;
#ifdef DEBUG
		std::cout << "[INDEX]:      " << (1ULL << index) << ": " << std::bitset<64>(1ULL << index) << std::endl;
#endif
		if ((1ULL << index) * 2 > bits) {
			return 0;
		}
	} while ((bits & (1ULL << index)) == 0);
	bits -= (1ULL << index);
	bits |= (1ULL << index) - 1;
	ulong palindrome = (bits & rotate_bits(bits));
#ifdef DEBUG
	std::cout << "[BITS]:       " << bits << ": " << std::bitset<64>(bits) << std::endl;
	std::cout << "[PALINDROME]: " << palindrome << ": " << std::bitset<64>(palindrome) << std::endl;
#endif
	return std::max(palindrome, next_palindrome(bits, index));
}

void test_case()
{
	ulong X;
	std::cin >> X;
#ifdef DEBUG
	std::cout << "[X]:          " << X << ": " << std::bitset<64>(X) << std::endl;
	std::cout << "[INV_X]:      " << rotate_bits(X) << ": " << std::bitset<64>(rotate_bits(X)) << std::endl;
#endif

	if ((X & rotate_bits(X)) == X) {
		std::cout << X << std::endl;
		return;
	}
	if (((X - 1) & X) == 0) {
		std::cout << X - 1 << std::endl;
		return;
	}
	std::cout << next_palindrome(X, 0) << std::endl;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t = 1;
	//std::cin >> t;

	while (t--)
	{
		test_case();
	}
	return 0;
}
