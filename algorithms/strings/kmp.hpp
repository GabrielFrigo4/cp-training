#pragma once
#include <vector>
#include <string>

std::vector<int> prefix_function(const std::string& s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

std::vector<int> kmp_match(const std::string& text, const std::string& pattern) {
    std::string concat = pattern + '#' + text;
    std::vector<int> pi = prefix_function(concat);
    std::vector<int> occurrences;
    int m = (int)pattern.length();
    for (int i = m + 1; i < (int)concat.length(); i++) {
        if (pi[i] == m) occurrences.push_back(i - 2 * m);
    }
    return occurrences;
}
