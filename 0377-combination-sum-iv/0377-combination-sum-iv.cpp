int solve(vector<int> &arr,int target,vector<int> &dp){
   if(target==0) return 1;
   if(dp[target]!=-1) return dp[target];
   dp[target]=0;
   for(int i=0;i<arr.size();i++){
       if(arr[i]<=target) dp[target]=dp[target]+solve(arr,target-arr[i],dp);
   }
   return dp[target];
}
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,dp);
    }
};