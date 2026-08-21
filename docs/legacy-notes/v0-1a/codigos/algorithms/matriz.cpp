#include <bits/stdc++.h>

#pragma region CODE
std::vector<std::vector<int64_t>> criar_matriz(const int64_t linhas, const int64_t colunas) {
	std::vector<std::vector<int64_t>> mat(linhas);
	for (int64_t linha = 0; linha < linhas; linha++)
		mat[linha] = std::vector<int64_t>(colunas);
	return mat;
}
#pragma endregion CODE

#pragma region UTILS
void print_matriz(std::vector<std::vector<int64_t>> mat)
{
	for (std::vector<int64_t> vec : mat) {
		for (int64_t e : vec) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}
#pragma endregion UTILS

#pragma region TEST
int main(void) {
	std::vector<std::vector<int64_t>> mat = criar_matriz(5, 7);
	print_matriz(mat);
    return 0;
}
#pragma endregion TEST