class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_lenght = 0;
        vector<int> list;
        for (int num : nums) {
            if (list.empty()) {
                list.push_back(num);
                continue;
            }
            if (list.back() < num) {
                list.push_back(num);
                continue;
            }
            
            auto it = lower_bound(list.begin(), list.end(), num);
            *it = num;
        }
        return list.size();
    }
};
