// Last updated: 7/26/2025, 2:43:20 PM
class Solution {
public:
    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        return dp[i][j] = false;
    }
    int solve(int i, int j, string& s, vector<vector<int>>& dp, vector<vector<int>>& isPalind){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(i, j, s, isPalind)) return 0 ; // if the string is already palindroms...no cut is required
        int ans = INT_MAX;
        for(int ind = i ; ind < j ; ind++){
            if(isPalindrome(i, ind, s, isPalind)){
                ans = min(ans,  1 + solve(ind + 1, j, s, dp, isPalind) );
            }
        }
        return dp[i][j] = ans;

        

    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>( n + 1, -1));
        vector<vector<int>> isPalind(n + 1, vector<int>( n + 1, -1));
        return solve(0, n - 1, s, dp, isPalind);
    }
};