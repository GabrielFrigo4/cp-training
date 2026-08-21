class Solution {
public:
    map<pair<int, int>, int> memo;
    int dp(vector<int>& nums, int target, int index, int sum) {
        if (index < 0 && sum == target) {
            return 1;
        }
        if (index < 0) {
            return 0;
        }

        if (memo.find({index, sum}) != memo.end()) {
            return memo[{index, sum}];
        }

        int positive = dp(nums, target, index - 1, sum + nums[index]);
        int negative = dp(nums, target, index - 1, sum - nums[index]);
        memo[{index, sum}] = positive + negative;
        return memo[{index, sum}];
    }    
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums, target, nums.size() - 1, 0);
    }
};