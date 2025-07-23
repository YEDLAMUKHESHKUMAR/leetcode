// Last updated: 7/23/2025, 10:42:58 AM
class Solution {
public:
    int solve (int i, int sum, int target, vector<int> &nums){
        if(i >= nums.size()){
            if(target == sum ) return 1;
            return 0;
        }
        int add = solve(i + 1, sum + 1 , target, nums);
        int del = solve(i + 1, sum - 1 , target, nums);
        return add + del;
    }
    int newSolve(int i , int target, vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        if(i >= n) {
            return target == 0;
        }
        if(target == 0) return 1;
        if(dp[i][target] != -1) return dp[i][target];
        int pick = 0;
        if(nums[i] <= target){
            pick = newSolve(i+1,target-nums[i], nums,dp);
        }
        int notPick = newSolve(i+1,target, nums,dp);
        return dp[i][target] =  pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // return solve(0,0,target,nums);

        // the dp answer for this question is diabolical T_T ( it questions my entire dp learning ..)
        // try it , if not get it..look notes

        // s1 = (totalSum + target) / 2;
        int totalSum = 0;
        for(int i = 0; i<n;i++){
            totalSum += nums[i];
        }
        if((totalSum + abs(target)) % 2 == 1 ) return 0;
        int targetSum = (totalSum + abs(target)) / 2 ;
        // vector<vector<int>> dp(n+1,vector<int> (targetSum + 1, -1));
        // return newSolve(0,targetSum,nums,dp);
        cout<<targetSum<<endl;
        vector<vector<int>> dp(n + 1, vector<int> (targetSum + 1 , 0));
        for(int i = 0 ;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i = 1 ;i<=n;i++){
            for(int sum = 0;sum <= targetSum ; sum++){
                int pick = 0;
                if(nums[i-1] <= sum){
                    pick = dp[i-1][sum - nums[i-1]];
                }
                int notPick = dp[i-1][sum];
                dp[i][sum] = pick + notPick;
            }
        }
        return dp[n][targetSum];



    }
};