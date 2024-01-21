int solve(int index,vector<int> &arr,int n,vector<int> &dp){
    if(index==n-1){
        return arr[n-1];
    }
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int pick=arr[index]+solve(index+2,arr,n,dp);
    int non_pick= 0+solve(index+1,arr,n,dp);
    return dp[index]=max(pick,non_pick);
}
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};