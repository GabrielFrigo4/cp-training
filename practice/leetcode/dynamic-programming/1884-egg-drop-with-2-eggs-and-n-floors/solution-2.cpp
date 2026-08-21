class Solution {
public:
    int twoEggDrop(int n) {
        const int eggs = 2;
        const int floors = 1000;
        int dp[floors + 1][eggs + 1] = {};
        return drop(n, eggs, dp);
    }

    template <size_t floors_t, size_t eggs_t>
    int drop(int floors, int eggs, int (&dp)[floors_t][eggs_t]) {
        if (eggs == 1 || floors <= 1) {
            return floors;
        }
        if (dp[floors][eggs] > 0) {
            return dp[floors][eggs];
        }
        int minimum = INT_MAX;
        for (int f = 1; f <= floors; f++) {
            int maximum = max(drop(f - 1, eggs - 1, dp), drop(floors - f, eggs, dp));
            minimum = min(minimum, maximum + 1);
        }
        dp[floors][eggs] = minimum;
        return dp[floors][eggs];
    }
};
