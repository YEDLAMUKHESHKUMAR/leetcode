class Solution {
public:
    int solve(int i, int m, int n, vector<vector<int>> &counts, vector<vector<vector<int>>> &dp){
        if(i >= counts.size()){
            if(m < 0 || n < 0) return -1e8;
            return 0;
        } 
        if(m == 0 && n == 0) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int pick = -1e8;
        if(m >= counts[i][0] && n >= counts[i][1]){
            pick = 1 + solve(i + 1, m - counts[i][0], n - counts[i][1], counts , dp);
        }
        int notPick = solve(i + 1, m, n, counts, dp);
        return dp[i][m][n] = max(pick , notPick);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        // got memo soln: ...note : it's better if we store the number of 0's and 1's before hand, instead of traversing and checking everytime in recurison...
        vector<vector<int>> counts(s.size(), vector<int> (2, 0));
        for(int i = 0; i<s.size();i++){
            int z = 0, o= 0;
            for(int j = 0; j<s[i].size();j++){
                if(s[i][j] == '0')z++;
                else o++;
            }
            counts[i][0] = z;
            counts[i][1] = o;
        } 
         
        vector<vector<vector<int>>> dp(s.size() , vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        return solve(0, m, n, counts, dp);
    }
};