#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::array<std::string, 8> S;
	for (std::string &_S : S) {
		std::cin >> _S;
	}

	std::array<bool, 8> rows;
	std::array<bool, 8> columns;
	rows.fill(true);
	columns.fill(true);
	for (size_t y = 0; y < S.size(); y++) {
		for (size_t x = 0; x < S[y].size(); x++) {
			if (S[y][x] == '#') {
				rows[y] = false;
				columns[x] = false;
			}
		}
	}

	std::cout << std::accumulate(rows.begin(), rows.end(), 0) * std::accumulate(columns.begin(), columns.end(), 0) << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
