#include <bits/stdc++.h>

int64_t fib(int64_t n) {
  int64_t e0 = 1, e1 = 1, e2 = 2;
  switch (n) {
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  }

  n -= 2;
  while (n > 0) {
    e2 = e2 + e1;
    std::swap(e1, e0);
    e1 = e1 + e0;
    n--;
  }
  return e2;
}

int main(void) {
  int64_t N;
  std::cin >> N;
  std::cout << fib(N) << std::endl;
  return 0;
}
