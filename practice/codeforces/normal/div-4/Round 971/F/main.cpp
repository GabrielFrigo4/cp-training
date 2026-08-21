#include <bits/stdc++.h>

int64_t chunk_sum(std::vector<int64_t> &sum, std::vector<int64_t> &A, const int64_t L, const int64_t R) {
    if (L > R) {
        return 0;
    }

    const int64_t chunk = (L - 1) / A.size();
    const int64_t lb = (L - 1) % A.size() + 1;
    const int64_t rb = (R - 1) % A.size() + 1;

    int64_t ln = (lb + chunk - 1) % A.size() + 1;
    int64_t rn = (rb + chunk - 1) % A.size() + 1;

    if (ln <= rn) {
        return sum[rn] - sum[ln-1];
    }
    else {
        return (sum[rn] - sum[0]) + (sum.back() - sum[ln-1]);
    }
}

int64_t query(std::vector<int64_t> &sum, std::vector<int64_t> &A, const int64_t L, const int64_t R) {
    const double DL = static_cast<double>(L);
    const double DR = static_cast<double>(R);
    const int64_t lb = std::ceil((DL - 1) / A.size());
    const int64_t rb = std::floor(DR / A.size());
    const int64_t times = rb - lb;

    int64_t count = 0;
    switch (times) {
        case -1:
            count += chunk_sum(sum, A, L, R);
            break;
        default:
            count += chunk_sum(sum, A, L, lb * A.size());
            count += chunk_sum(sum, A, rb * A.size() + 1, R);
            count += times * sum.back();
            break;
    }

    return count;
}

void test_case(void) {
    int64_t N, Q;
    std::cin >> N >> Q;

    std::vector<int64_t> A(N);
    for (int64_t &a : A) {
        std::cin >> a;
    }

    std::vector<int64_t> sum(N + 1);
    for (int64_t i = 1; i <= N; i++) {
        sum[i] = sum[i-1] + A[i-1];
    }

    for (int64_t q = 0; q < Q; q++) {
        int64_t L, R;
        std::cin >> L >> R;
        int64_t s = query(sum, A, L, R);
        std::cout << s << std::endl;
    }

    return;
}

int32_t main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    int64_t t;
    std::cin >> t;

    for (int32_t i = 0; i < t; i++) {
        test_case();
    }
    return 0;
}
