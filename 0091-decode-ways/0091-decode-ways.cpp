class Solution {
public:
    int solve(int i,string &s,vector<int> &dp){         // memoization will work :) 
        int n= s.size(); 
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i]; 
        if(s[i] == '0') return dp[i] =  0 ;   // single or pair is not possible
        int ans = solve(i+1,s,dp);
        if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
            ans+=(solve(i+2,s,dp));
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1); 
        // dp[n] = 1;
        return solve(0,s,dp);
    }
};