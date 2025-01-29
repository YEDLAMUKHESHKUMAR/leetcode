class Solution {
public: 
    int solve(int i, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(i < 0) return 1e8;
        if(dp[i][amount] != -1) return dp[i][amount];
        int pick = 1e8;
        if(amount - coins[i] >= 0){
            pick = 1 + solve(i,amount - coins[i] , coins,dp);
        }
        int notPick = 0 + solve(i-1,amount,coins,dp);
        return dp[i][amount] = min(pick,notPick);
    }
    
    /*
    
        5
       /
      5
     /\
    0. _
      / \
     _   

    */



    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        // vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        // int ans = solve(n-1,amount,coins,dp) ;
        // if(ans == 1e8) return -1;
        // return ans;
        // vector<vector<int>> dp(n+1,vector<int> (amount+1,1e8));
        // for(int i = 0 ;i <=n;i++){
        //     dp[i][0] = 0; 
        // }
        // for(int i = 1 ;i<=n ;i++){
        //     for(int j = 1;j<=amount;j++){
        //         int pick = 1e8; 
        //         if(j >= coins[i-1]){
        //             pick = 1 + dp[i][j- coins[i-1]];
        //         }
        //         int notPick = dp[i-1][j];
        //         dp[i][j] = min(pick,notPick);
        //     }
        // }
        // if(dp[n][amount] >= 1e8) return -1;
        // return dp[n][amount];

        vector<int> dp(amount + 1, 1e8);
        dp[0] = 0;
        for(int sum = 1; sum <= amount; sum++){
            for(int i = 0;i<n;i++){
                if(coins[i] <= sum){
                    dp[sum] = min(dp[sum] , 1 + dp[sum - coins[i]]);
                }
                else break;
            }
        }
        // for(int i = 0; i<= amount ;i++) cout<<dp[i]<<" ";
        return dp[amount] == 1e8 ? -1 : dp[amount];

    }
};