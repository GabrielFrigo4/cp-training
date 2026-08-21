class Solution {
public:
    int dp(vector<int>& nums, int target, int index, int sum) {
        if (index < 0 && sum == target) {
            return 1;
        }
        if (index < 0) {
            return 0;
        }

        int positive = dp(nums, target, index - 1, sum + nums[index]);
        int negative = dp(nums, target, index - 1, sum - nums[index]);
        return positive + negative;
    }    
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums, target, nums.size() - 1, 0);
    }
};