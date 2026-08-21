#include <bits/stdc++.h>

void sum_bit(std::vector<int64_t> &V, int64_t v) {
  int64_t i = 0;
  while (v > 0) {
    int64_t r = v % 2;
    v /= 2;
    V[i] += r;
    i++;
  }
}

int main(void) {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> V(sizeof(int64_t)*8);
  for (int64_t i = 0; i < N; i++) {
    int64_t v;
    std::cin >> v;
    sum_bit(V, v);
  }

  for (int64_t i = 0; i < N; i++) {
    int64_t numb = 0;
    for (int64_t e = 0; e < V.size(); e++) {
      if (V[e] > 0) {
	V[e]--;
	numb += std::pow(2, e);
      }
    }
    std::cout << numb << " ";
  }
  std::cout << std::endl;
  return 0;
}
