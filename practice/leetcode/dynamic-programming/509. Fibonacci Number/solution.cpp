class Solution {
public:
    int fib(int n) {
        array<int, 2> dp = {0, 1};
        if (n < 2) {
            return dp[n];
        }

        for (int i = 2; i < n; i++) {
            array<int, dp.size()> tmp = {dp[1], dp[0]+dp[1]};
            for (int i = 0; i < tmp.size(); i++) {
                dp[i] = tmp[i];
            }
        }
        return dp[0] + dp[1];
    }
};