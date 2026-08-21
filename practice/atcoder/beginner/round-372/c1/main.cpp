#include <bits/stdc++.h>
#include <algorithm>

void test_run(void) {
	int64_t N, Q;
	std::string S, S1;
	std::cin >> N >> Q;
	std::cin >> S;

	const std::string abc = "ABC";
	int64_t count = 0;
	{
		std::size_t index = 0;
		while ((index = S.find(abc, index)) != std::string::npos) {
			count++;
			index += abc.length();
		}
	}

	for (int64_t i = 0; i < Q; i++) {
		int64_t X;
		char C;
		std::cin >> X >> C;
		S1 = S;
		S[X-1] = C;

		if (X > 2) {
			if (S1[X-3] == abc[0] && S1[X-2] == abc[1] && S1[X-1] == abc[2] && S[X-1] != abc[2]) {
				count--;
			}
			
			if (S1[X-3] == abc[0] && S1[X-2] == abc[1] && S1[X-1] != abc[2] && S[X-1] == abc[2]) {
				count++;
			}
		}
		if (X > 1 && X < S.length()) {
			if (S1[X-2] == abc[0] && S1[X-1] == abc[1] && S1[X] == abc[2] && S[X-1] != abc[1]) {
				count--;
			}
			
			if (S1[X-2] == abc[0] && S1[X-1] != abc[1] && S1[X] == abc[2] && S[X-1] == abc[1]) {
				count++;
			}
		}
		if (X < S.length() - 1) {
			if (S1[X-1] == abc[0] && S1[X] == abc[1] && S1[X+1] == abc[2] && S[X-1] != abc[0]) {
				count--;
			}
			
			if (S1[X-1] != abc[0] && S1[X] == abc[1] && S1[X+1] == abc[2] && S[X-1] == abc[0]) {
				count++;
			}
		}

		std::cout << count << std::endl;
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
