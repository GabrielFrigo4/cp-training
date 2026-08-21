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

void test_run(void) {
	int n, a, b, k, f;
	std::cin >> n >> a >> b >> k >> f;

	int total_cost = 0;
	std::map<std::pair<std::string, std::string>, int> map_cost;

	std::pair<std::string, std::string> last_travel;
	for (int i = 0; i < n; i++) {
		std::pair<std::string, std::string> current_travel;
		std::cin >> std::get<0>(current_travel) >> std::get<1>(current_travel);

		int cost = 0;
		if (i > 0 && std::get<1>(last_travel) == std::get<0>(current_travel)) {
			cost = b;
		}
		else {
			cost = a;
		}
		total_cost += cost;

		std::pair<std::string, std::string> cost_travel = current_travel;
		if (std::get<0>(cost_travel) > std::get<1>(cost_travel)) {
			std::swap(std::get<0>(cost_travel), std::get<1>(cost_travel));
		}
		if (!map_cost.contains(cost_travel)) {
			map_cost[cost_travel] = 0;
		}
		map_cost[cost_travel] += cost;

		last_travel = current_travel;
	}

	std::vector<int> vec_cost;
	for (auto [key, value] : map_cost) {
		vec_cost.push_back(value);
	}
	std::sort(vec_cost.rbegin(), vec_cost.rend());

	for (int i = 0; i < std::min(static_cast<size_t>(k), vec_cost.size()); i++) {
		if (vec_cost[i] >= f) {
			total_cost += f;
			total_cost -= vec_cost[i];
		}
		else {
			break;
		}
	}

	std::cout << total_cost << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
