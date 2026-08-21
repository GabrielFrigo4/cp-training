#pragma once
#include <vector>
#include <numeric>
#include <utility>

struct DSU {
    int n;
    std::vector<int> parent_or_size;

    explicit DSU(int n = 0) : n(n), parent_or_size(n, -1) {}

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    bool merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

    int size(int a) {
        return -parent_or_size[leader(a)];
    }
};
