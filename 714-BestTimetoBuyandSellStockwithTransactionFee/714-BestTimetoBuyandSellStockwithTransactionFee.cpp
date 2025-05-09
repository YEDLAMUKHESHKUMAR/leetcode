// Last updated: 5/9/2025, 11:36:34 AM
class Solution {
public:
    int solve(int i, bool buy, int fee, vector<int> &prices , vector<vector<int>> &dp){
        int n = prices.size();
        if(i >= n){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy == false){
            int buyStock = solve( i + 1, true, fee, prices, dp ) - prices[i];
            int donotBuy = solve(i + 1, buy, fee, prices, dp);
            return dp[i][buy] = max(buyStock, donotBuy);
        }
        else{
            int sellStock = solve(i, false, fee, prices, dp) + prices[i] - fee;
            int donotSell = solve(i + 1, buy, fee, prices, dp);
            return dp[i][buy] = max(sellStock, donotSell);
        }
        return 0;
         
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int> (2, -1));
        return solve(0, false, fee, prices, dp);
    }
};