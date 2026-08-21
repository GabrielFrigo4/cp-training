#include <bits/stdc++.h>

std::vector<int64_t> fatores_primos(int64_t N) {
  std::vector<int64_t> primos;
  int64_t fator = 2;
  if (N % fator == 0) {
    primos.push_back(fator);
    while (N % fator == 0) {
      N /= fator;
    }
  }
  fator = 3;
  while (N > 1) {
    if (N % fator == 0) {
      primos.push_back(fator);
    }
    while (N % fator == 0) {
      N /= fator;
    }
    fator += 2;
  }
  return primos;
}

int64_t pratos_totais(const std::vector<int64_t> &V, const int64_t X) {
  int64_t count = 0;
  std::vector<int64_t> primos = fatores_primos(X);
  for (int64_t v : V) {
    bool is_div = false;
    for (int64_t p : primos) {
      if (v % p == 0) {
	is_div = true;
	break;
      }
    }
    if (!is_div) {
      count++;
    }
  }
  return std::pow(2, count);
}

int main(void) {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> V(N);
  for (int64_t &v : V) {
    std::cin >> v;
  }

  int64_t Q;
  std::cin >> Q;
  for (int64_t i = 0; i < Q; i++) {
    int64_t X;
    std::cin >> X;
    std::cout << pratos_totais(V, X) % (int64_t)(std::pow(10, 9) + 7) << std::endl;
  }
}
