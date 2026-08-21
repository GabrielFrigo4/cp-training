#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	std::string S;
	std::cin >> S;

	std::sort(S.begin(), S.end());
	std::cout << (S == "ABC" ? "Yes" : "No") << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
