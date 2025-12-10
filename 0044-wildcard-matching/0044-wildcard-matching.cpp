class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        int n = s.size();
        int m = p.size();
        
        if(i >= n){
            for(int k = j ; k < m; k++) if(p[k] != '*') return false;
            return true;
        }
        if(j >= m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '*'){
            int take = solve(i + 1, j, s, p, dp)  ;
            int leave = solve(i, j + 1, s, p, dp) ;
            return dp[i][j] = take | leave;
        }
        else if( s[i] == p[j]  || p[j] == '?'){
            if(solve(i + 1, j + 1, s, p, dp)) return dp[i][j] = true;
        }
        return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int> ( m + 1, -1));
        return solve(0, 0, s, p, dp);
    }
};