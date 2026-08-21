#include <bits/stdc++.h>
const std::string global_apha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*/#!";

bool in_str(std::string str, char c) {
	for (char s : str) {
		if (s == c) {
			return true;
		}
	}
	return false;
}

int main(void) {
	int64_t K, N;
	std::cin >> K >> N;
	
	std::string alpha;
	std::cin >> alpha;

	std::string msg;
	std::cin >> msg;

	for (char m : msg) {
		if (!in_str(alpha, m)) {
			std::cout << "N" << std::endl;
			return 0;
		}
	}

	std::cout << "S" << std::endl;
	return 0;
}
