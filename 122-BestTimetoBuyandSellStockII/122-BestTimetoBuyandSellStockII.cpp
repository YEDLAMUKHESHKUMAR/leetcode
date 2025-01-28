class Solution {
public:
    int solve(int i, int flag, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(i >= n){
            if(flag == true){
                return -1e9;
            }
            return 0;
        } 
        if(dp[i][flag] != -1) return dp[i][flag];
        int ans = 0;
        if(flag == 0){  // buy
            int buy = (-prices[i]) + solve(i + 1, !flag , prices, dp );
            int notBuy = solve(i + 1, flag, prices,dp);
            ans = max(buy , notBuy);
        }
        else{
            int sell  = (prices[i]) +  solve(i, !flag, prices, dp);
            // int notsell = solve(i + 1, flag, prices, dp);
            ans = sell;
        }
        return dp[i][flag] = ans;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return solve(0, 0, prices, dp);
    }
};
        // int maxi = *max_element(prices.begin(), prices.end());  no need...just store ind :)
        // vector<vector<vector<long long>>> dp(n , vector<vector<long long>> (n + 1, vector<long long> (2, -1))); 
        // we no need to save the prevInd where u have stored, just , whenver you buy , you do  -x + solve(...)
        // then we just need 2d dp 