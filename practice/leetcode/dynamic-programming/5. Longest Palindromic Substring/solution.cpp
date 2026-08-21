class Solution {
public:
    string longestPalindrome(string s) {
        int ans_pos = 0;
        int ans_length = 1;
        vector dp(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j] && (i-j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    if (ans_length < i - j + 1) {
                        ans_length = i - j + 1;
                        ans_pos = j;
                    }
                }
            }
        }
        return s.substr(ans_pos, ans_length);
    }
};