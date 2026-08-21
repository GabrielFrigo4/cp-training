#pragma once
#include <vector>
#include <algorithm>
#include <bit>

template <typename T>
struct SparseTable {
    int n, K;
    std::vector<std::vector<T>> st;

    SparseTable(const std::vector<T>& a) : n(a.size()), K(std::bit_width((unsigned)n)) {
        st.assign(K, std::vector<T>(n));
        st[0] = a;
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[j][i] = std::min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query_min(int l, int r) const {
        int j = std::bit_width((unsigned)(r - l + 1)) - 1;
        return std::min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
