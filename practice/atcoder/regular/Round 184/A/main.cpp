#include <bits/stdc++.h>
#include <algorithm>

std::vector<std::vector<int16_t>> request_groups;
std::vector<int16_t> counterfeit_coins;

int16_t request(int16_t x, int16_t y) {
	std::cout << "? " << x << " " << y << std::endl;
	std::cout << std::flush;

	int16_t req;
	std::cin >> req;
	return req;
}

void answer() {
	std::cout << "!";
	for (int16_t counterfeit_coin : counterfeit_coins) {
		std::cout << " " << counterfeit_coin;
	}
	std::cout << std::endl;
	std::cout << std::flush;
}

void test_run(void) {
	int16_t N, M, Q;
	std::cin >> N >> M >> Q;

	int16_t coin_ok = -1;
	for (std::size_t i = 0; i < 90; i++) {
		const int16_t up = 11*i + 1;
		std::vector<int16_t> g1 = { up };
		std::vector<int16_t> g2 = {};

		for (int16_t j = up + 1; j <= up + 10; j++) {
			int16_t req = request(up, j);
			switch (req) {
				case 1:
					g2.push_back(j);
					break;
				case 0:
					g1.push_back(j);
					break;
				case -1:
					return;
					break;
			}
		}

		if (!g2.empty()) {
			request_groups.push_back(g1);
			request_groups.push_back(g2);
		}
		else if (coin_ok == -1) {
			coin_ok = up;
		}
	}

	for (std::size_t i = 0; i < request_groups.size(); i += 2) {
		int16_t req = request(coin_ok, request_groups[i][0]);
		switch (req) {
			case 1:
				counterfeit_coins.insert(counterfeit_coins.end(), request_groups[i].begin(), request_groups[i].end());
				break;
			case 0:
				counterfeit_coins.insert(counterfeit_coins.end(), request_groups[i+1].begin(), request_groups[i+1].end());
				break;
			case -1:
				return;
				break;
		}
	}

	for (int16_t i = 991; i <= 1000; i++) {
		int16_t req = request(coin_ok, i);
		switch (req) {
			case 1:
				counterfeit_coins.push_back(i);
				break;
			case 0:
				continue;
				break;
			case -1:
				return;
				break;
		}
	}

	answer();
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
