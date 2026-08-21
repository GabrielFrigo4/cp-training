#include <bits/stdc++.h>

int main(void) {
  int64_t N;
  std::cin >> N;

  std::vector<std::vector<int64_t>> matriz(N);
  for (int64_t i = 0; i < N; i++) {
    std::vector<int64_t> vec(N);
    for (int64_t &e : vec) {
      std::cin >> e;
    }
    matriz[i] = vec;
  }
  
  const int64_t e1 = matriz[0][0];
  const int64_t e2 = matriz[0][N-1];
  const int64_t e3 = matriz[N-1][N-1];
  const int64_t e4 = matriz[N-1][0];

  std::vector<int64_t> pontas = { e1, e2, e3, e4 };
  std::sort(pontas.begin(), pontas.end());
  const int64_t min = pontas.front();
  if(e1 == min) {
    std::cout << 0 << std::endl;
  }
  else if(e2 == min) {
    std::cout << 1 << std::endl;
  }
  else if(e3 == min) {
    std::cout << 2 << std::endl;
  }
  else if(e4 == min) {
    std::cout << 3 << std::endl;
  }
  
  return 0;
}
