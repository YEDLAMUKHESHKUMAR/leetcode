class Solution {
public:
  int longestIdealString(string s, int k) {
        int ans = 0, n = s.length();
        vector<int> dp(26, 0);
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            dp[ch] += 1;
            for (int j = max(0, ch - k); j <= min(25, ch + k); j++) {
                if (j != ch)
                    dp[ch] = max(dp[j] + 1, dp[ch]);
            }
            ans = max(ans, dp[ch]);
        }
        return ans;
    }
};