class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_lenght = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;
            max_lenght = max(max_lenght, dp[i]);
        }
        return max_lenght;
    }
};
