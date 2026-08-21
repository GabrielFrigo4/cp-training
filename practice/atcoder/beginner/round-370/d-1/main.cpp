#include <bits/stdc++.h>
#include <algorithm>

std::vector<std::vector<bool>> create_matriz(const int64_t H, const int64_t W, const bool value) {
	std::vector<std::vector<bool>> matriz(H);
	for (std::vector<bool> &rows : matriz) {
		rows = std::vector<bool>(W, value);
	}
	return matriz;
}

int64_t destroy_wall(std::vector<std::vector<bool>> &matriz, const int64_t H, const int64_t W, const int64_t R, const int64_t C) {
	if (matriz[R-1][C-1]) {
		matriz[R-1][C-1] = false;
		return 1;
	}
	else {
		int64_t count = 0;
		int64_t r = R-1, c = C-1;
		while (!matriz[r][c]) {
			r--;
			if (r < 0) {
				break;
			}
		}
		if (r >= 0) {
			matriz[r][c] = false;
			count++;
		}

		r = R-1, c = C-1;
		while (!matriz[r][c]) {
			r++;
			if (r >= H) {
				break;
			}
		}
		if (r < H) {
			matriz[r][c] = false;
			count++;
		}

		r = R-1, c = C-1;
		while (!matriz[r][c]) {
			c--;
			if (c < 0) {
				break;
			}
		}
		if (c >= 0) {
			matriz[r][c] = false;
			count++;
		}

		r = R-1, c = C-1;
		while (!matriz[r][c]) {
			c++;
			if (c >= W) {
				break;
			}
		}
		if (c < W) {
			matriz[r][c] = false;
			count++;
		}
		return count;
	}
}

void test_case(void) {
	int64_t H, W, Q;
	std::cin >> H >> W >> Q;

	int64_t count = H * W;
	std::vector<std::vector<bool>> matriz = create_matriz(H, W, true);
	for (int64_t i = 0; i < Q; i++) {
		int64_t R, C;
		std::cin >> R >> C;
		count -= destroy_wall(matriz, H, W, R, C);
	}

	std::cout << count << std::endl;
	return;
}

int32_t main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
