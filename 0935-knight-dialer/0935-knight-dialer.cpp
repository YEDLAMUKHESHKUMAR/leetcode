class Solution {
public:
    vector<vector<int>> GoToNextDailer = {   // :)
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int mod = 1e9+7;
    int solve(int remainingN , int currDailer,vector<vector<int>> &dp){ // :) 
        if(remainingN == 0) return 1;
        if(dp[remainingN][currDailer] != -1){
            return dp[remainingN][currDailer];
        }
        int ans =  0 ;
        for(int nextDailer : GoToNextDailer[currDailer] ){       // memoization will work  :)
            ans = (ans + solve(remainingN - 1 , nextDailer,dp ))%mod; 
        }
        return dp[remainingN][currDailer] = ans;
    }
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<int>> dp(n,vector<int> (10,-1));
        for(int i=0;i<10;i++){
            ans = (ans + solve(n-1,i,dp))%mod;
        }
        return ans%mod;

    }
};