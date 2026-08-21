#pragma once
#include <vector>
#include <cstdint>

template <typename T = int64_t>
struct FenwickTree {
    int n;
    std::vector<T> tree;

    explicit FenwickTree(int n = 0) : n(n), tree(n + 1, 0) {}

    void add(int i, T delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }

    T query(int i) const {
        T sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    T query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
