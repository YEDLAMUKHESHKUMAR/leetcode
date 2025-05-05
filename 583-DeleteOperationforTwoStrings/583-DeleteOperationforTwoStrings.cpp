// Last updated: 5/5/2025, 10:42:14 AM
class Solution {
public:
    int solve(int i, int j, string &s1, string& s2, int n, int m, vector<vector<int>> &dp){
        if(i >= n || j >= m) {
            return (n - i  + m - j);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i + 1 , j + 1, s1, s2, n, m , dp);
        }
        else {
            int left = 1 + solve(i + 1 , j , s1, s2, n, m , dp);
            int right = 1 + solve(i, j + 1 , s1, s2, n, m , dp);
            return dp[i][j] = min(left, right);
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(0, 0, s1, s2, n ,m, dp);
    }
};