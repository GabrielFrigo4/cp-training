#pragma once
#include <vector>
#include <algorithm>

template <typename T>
int longest_increasing_subsequence(const std::vector<T>& a) {
    std::vector<T> tails;
    for (const auto& x : a) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}
