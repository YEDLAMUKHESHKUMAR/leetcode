// Last updated: 6/25/2025, 9:35:27 PM
class Solution {
public:
    bool solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        int n = s.size(), m = t.size();
        if(i >= n && j >= m) return true;
        if(j >= m && i < n) return false;
        if(i >= n){
            for(int k = j ; k < m ;k++){
                if(k + 1 < m && t[k + 1] == '*') k++;
                else return false; 
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if( j + 1 < m && t[j + 1] == '*' ){
            bool skip = solve(i, j + 2, s, t,dp);
            bool take = false;
            if( t[j] == '.' || t[j] == s[i] ){
                take = solve(i + 1, j, s, t,dp);
            }
            return dp[i][j] = skip | take;
        }
        else if( s[i] == t[j] || t[j] == '.' ){
            return dp[i][j] = solve(i + 1, j + 1, s, t,dp);
        }
        // else return false;
        else return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        // return true;
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int> ( m + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};