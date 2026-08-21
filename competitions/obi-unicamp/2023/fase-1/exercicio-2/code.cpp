#include <bits/stdc++.h>

int32_t main()
{
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	int16_t M, N;
	std::cin >> M >> N;

	int16_t **estoque = (int16_t **)malloc(sizeof(int16_t *) * M);
	for (int16_t y = 0; y < M; y++)
	{
		estoque[y] = (int16_t *)malloc(sizeof(int16_t) * N);
		for (int16_t x = 0; x < N; x++)
		{
			int16_t item;
			std::cin >> item;
			estoque[y][x] = item;
		}
	}

	int16_t P, compras = 0;
	std::cin >> P;
	for (int16_t i = 0; i < P; i++)
	{
		int16_t I, J;
		std::cin >> I >> J;
		int16_t &item = estoque[I - 1][J - 1];
		if (item > 0)
		{
			item--;
			compras++;
		}
	}

	for (int16_t y = 0; y < M; y++)
	{
		free(estoque[y]);
	}
	free(estoque);

	std::cout << compras << std::endl;
	return 0;
}
