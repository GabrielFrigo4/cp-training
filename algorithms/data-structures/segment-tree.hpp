#pragma once
#include <vector>
#include <functional>

template <typename T>
struct SegmentTree {
    int n;
    std::vector<T> tree;
    T identity;
    std::function<T(T, T)> merge_op;

    SegmentTree(int n, T identity, std::function<T(T, T)> merge_op)
        : n(n), tree(4 * n, identity), identity(identity), merge_op(merge_op) {}

    void build(const std::vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = merge_op(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(2 * v, tl, tm, pos, new_val);
        else update(2 * v + 1, tm + 1, tr, pos, new_val);
        tree[v] = merge_op(tree[2 * v], tree[2 * v + 1]);
    }

    T query(int v, int tl, int tr, int l, int r) const {
        if (l > r) return identity;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return merge_op(
            query(2 * v, tl, tm, l, std::min(r, tm)),
            query(2 * v + 1, tm + 1, tr, std::max(l, tm + 1), r)
        );
    }

    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
    T query(int l, int r) const { return query(1, 0, n - 1, l, r); }
};
