class Solution {
public:
    bool solve(int i, int j ,string& s, string& t, vector<vector<int>> &dp){
        int n = s.size(); int m = t.size();
        if(i >= n){
            for(int k = j ;k <m;k++) if(t[k] != '*') return false;
            return true;
        }
        if(j >= m){
            if(i < n) return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        // cout<<1<<endl;
        if(t[j] == '?' || (s[i] == t[j])){
            // cout<<1<<" ";
            if(solve(i + 1, j + 1, s, t,dp) == true) return dp[i][j] = true;
            // return skip;
        }
        else if(t[j] != '*' && (s[i] != t[j]) ) return dp[i][j] = false;
        else{
            if(solve(i, j + 1 , s, t, dp) == true) return dp[i][j] = true;
            cout<<1<<" ";
            for(int k = i ; k <n;k++){
                if(solve(k + 1, j + 1, s, t,dp ) == true) return dp[i][j] = true;
            }
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string t) {
        int n= s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(0, 0, s, t, dp);

    }
};