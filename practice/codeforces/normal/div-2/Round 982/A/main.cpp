#include <bits/stdc++.h>
#include <algorithm>

void draw(std::vector<std::vector<bool>> &mat, const int64_t w, const int64_t h) {
	for (size_t y = h; y > 0; y--) {
		if (mat[y][w] == true) {
			break;
		}
		for (size_t x = w; x > 0; x--) {
			if (mat[y][x] == false) {
				mat[y][x] = true;
			}
			else {
				break;
			}
		}
	}
}

void test_case(void) {
	int64_t n;
	std::cin >> n;

	std::vector<std::pair<int64_t, int64_t>> stamps(n);
	for (auto &[w, h] : stamps) {
		std::cin >> w >> h;
	}

	const size_t mat_size = 102;
	const size_t count_size = 100;
	std::vector mat(mat_size, std::vector<bool>(mat_size, false));

	for (auto const[w, h] : stamps) {
		draw(mat, w, h);
	}

	int64_t count = 0;
	for (size_t y = 1; y <= count_size; y++) {
		if (mat[y][1] == false) {
			break;
		}
		for (size_t x = 1; x <= count_size; x++) {
			if (mat[y][x] == false) {
				break;
			}
			count += !mat[y][x+1];
			count += !mat[y][x-1];
			count += !mat[y+1][x];
			count += !mat[y-1][x];
		}
	}

	std::cout << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	for (int32_t i = 0; i < t; i++) {
		test_case();
	}
	return 0;
}
