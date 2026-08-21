#include <bits/stdc++.h>

#pragma region CODE
void merge_sort(std::vector<int64_t> &vec) {
	if (vec.size() <= 1)
		return;
	const int64_t mid = vec.size() / 2;
	std::vector<int64_t> v_a(vec.begin(), vec.begin() + mid);
	std::vector<int64_t> v_b(vec.begin() + mid, vec.end());
	merge_sort(v_a);
	merge_sort(v_b);
	std::merge(v_a.begin(), v_a.end(), v_b.begin(), v_b.end(), vec.begin());
}
#pragma endregion CODE

#pragma region UTILS
void print_vector(std::vector<int64_t> vec)
{
	std::cout << "{ ";
	for (int64_t e : vec)
		std::cout << e << " ";
	std::cout << "}" << std::endl;
}
#pragma endregion UTILS

#pragma region TEST
int main(void) {
	std::vector<int64_t> vec = { 4, 7, 1, 9, 2, 5, 8, 3, 10, 6 };
	std::cout << "merge_sort({ 4 7 1 9 2 5 8 3 10 6 }) = ";
	merge_sort(vec);
	print_vector(vec);
}
#pragma endregion TEST