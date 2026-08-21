#include <bits/stdc++.h>
#include <algorithm>

void test_case()
{
	int64_t N;
	std::cin >> N;

	int64_t T = 0;
	for (int64_t i = 0; i < N; i++)
	{
		int64_t H;
		std::cin >> H;
		T += (H / 5) * 3;
		H %= 5;
		while (H > 0)
		{
			if (T % 3 == 2)
			{
				H -= 3;
				T++;
			}
	  		else
	  		{
	  			H--;
	  			T++;
	  		}
		}
	}

	std::cout << T << std::endl;
	return;
}

int32_t main()
{
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	test_case();
	return 0;
}
