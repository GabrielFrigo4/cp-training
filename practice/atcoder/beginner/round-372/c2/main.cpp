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

		std::size_t start_i = static_cast<std::size_t>(std::max(static_cast<int64_t>(1), X-2));
		std::size_t end_i = static_cast<std::size_t>(std::min(static_cast<int64_t>(S.length()), X+2));
		std::size_t length = end_i - start_i + 1;

		std::string subS = S.substr(start_i-1, length);
		std::string subS1 = S1.substr(start_i-1, length);

		int64_t find_s = (subS.find(abc) != std::string::npos);
		int64_t find_s1 = (subS1.find(abc) != std::string::npos);
		count += find_s - find_s1;

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
