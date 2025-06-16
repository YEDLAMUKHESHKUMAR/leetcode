// Last updated: 6/16/2025, 12:04:23 PM
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // cbbd
        // dbbc
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 1 ; i<= n;i++){
            for(int j = 1 ; j<= n; j++){
                int len = 0;
                if(s[i - 1] == t[j-1]){
                    len = 1 + dp[i - 1 ][j - 1];
                }
                else{
                    len = max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = len;
            }
        }
        return dp[n][n];
    }
};