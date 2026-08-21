class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int opt = 0; opt < (1 << nums.size()); opt++) {
            int tmp = 0;
            for (int i = 0; i < nums.size(); i++) {
                bool bit = (opt & (1 << i)) != 0;
                tmp += nums[i] * bit;
                tmp -= nums[i] * (1-bit);
            }
            sum += tmp == target;
        }
        return sum;
    }
};