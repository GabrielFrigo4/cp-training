#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::string S;
	std::cin >> S;

	std::map<char, int64_t> mp;
	for (int64_t i = 0; i < S.size(); i++) {
		mp[S[i]] = i;	
	}

	int64_t length = 0;
	for (char c = 'A'; c != 'Z'; c++) {
		length += std::abs(mp[c] - mp[c+1]);
	}

	std::cout << length << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
