#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	char s_ab, s_ac, s_bc;
	std::cin >> s_ab >> s_ac >> s_bc;
	const bool S_AB = (s_ab == '>');
	const bool S_AC = (s_ac == '>');
	const bool S_BC = (s_bc == '>');

	int64_t A = 0, B = 0, C = 0;
	A += S_AB;
	A += S_AC;
	B += !S_AB;
	B += S_BC;
	C += !S_AC;
	C += !S_BC;

	if (A == 1) {
		std::cout << "A" << std::endl;
	}
	if (B == 1) {
		std::cout << "B" << std::endl;
	}
	if (C == 1) {
		std::cout << "C" << std::endl;
	}

	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
