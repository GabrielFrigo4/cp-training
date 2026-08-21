class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        int base = 0;
        int sum = nums[base];
        for (int i = 1; i < prefix.size(); i++) {
            if (sum < prefix[i] - prefix[base]) {
                sum = prefix[i] - prefix[base];
            }
            if (prefix[i] <= prefix[base]) {
                base = i;
            }
        }
        return sum;
    }
};