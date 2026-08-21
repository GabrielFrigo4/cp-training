#pragma once
#include <cstdint>

int64_t power(int64_t base, int64_t exp, int64_t mod = 1000000007) {
    int64_t res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

int64_t mod_inv(int64_t n, int64_t mod = 1000000007) {
    return power(n, mod - 2, mod);
}
