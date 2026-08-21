#pragma once
#include <vector>
#include <cstdint>

struct LinearSieve {
    std::vector<int> primes;
    std::vector<int> min_prime;

    explicit LinearSieve(int n) : min_prime(n + 1, 0) {
        for (int i = 2; i <= n; ++i) {
            if (min_prime[i] == 0) {
                min_prime[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > min_prime[i] || (int64_t)i * p > n) break;
                min_prime[i * p] = p;
            }
        }
    }

    bool is_prime(int x) const { return x >= 2 && min_prime[x] == x; }

    std::vector<std::pair<int, int>> factorize(int x) const {
        std::vector<std::pair<int, int>> res;
        while (x > 1) {
            int p = min_prime[x], cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            res.emplace_back(p, cnt);
        }
        return res;
    }
};
