#pragma once
#include <vector>
#include <cstdint>

struct Combinatorics {
    int n;
    int64_t mod;
    std::vector<int64_t> fact, inv_fact;

    Combinatorics(int n, int64_t mod = 1000000007) : n(n), mod(mod), fact(n + 1), inv_fact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[n] = power(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; --i) inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }

    static int64_t power(int64_t base, int64_t exp, int64_t mod) {
        int64_t res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    int64_t nCr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
    }

    int64_t nPr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[n - r] % mod;
    }
};
