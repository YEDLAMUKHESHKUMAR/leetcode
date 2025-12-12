class Solution {
public:
    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& palindrome){
        if(i >= j) return true;
        if(palindrome[i][j] != -1) return palindrome[i][j];
        if(s[i] == s[j]) return palindrome[i][j] = isPalindrome(i + 1, j - 1, s, palindrome);
        return palindrome[i][j] = false;
    }
    int solve(int i, string& s, vector<int>& dp, vector<vector<int>>& palindrome){
        int n = s.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        if(isPalindrome(i , n - 1, s, palindrome)) return 0;
        int ans = INT_MAX;
        for(int ind = i ; ind < n ;ind++){
            if(isPalindrome(i, ind, s, palindrome)){
                ans = min(ans, 1 + solve(ind + 1, s, dp, palindrome));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> palindrome(n + 1, vector<int> (n + 1, -1) );
        vector<int> dp(n + 1, -1);
        return solve(0, s, dp, palindrome);
    }
};