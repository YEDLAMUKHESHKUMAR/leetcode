// int solve(int ind,vector<int> cost){
//     if(ind<2){
//         return cost[ind];
//     }
//     int left=solve(ind-1,cost)+cost[ind];
//     int right=INT_MAX;
//     if(ind>1){
//         right=solve(ind-2,cost)+cost[ind];
//     }
//     return min(left,right);
// }
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n+1];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i] =cost[i]+ min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};