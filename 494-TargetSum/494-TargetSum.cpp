// Last updated: 7/23/2025, 10:56:40 AM
class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size()) {
            if(target == 0) return 1;
            return 0;
        }
        // if(target == 0) return 1;
        if(dp[i][target] != -1) return dp[i][target];
        int take = 0;
        if(nums[i] <= target){
            take = solve(i + 1, target - nums[i], nums, dp);
        }
        int notTake = solve(i + 1, target, nums, dp);
        return dp[i][target] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n ; i++){
            total+=nums[i];
        }
        if( (total + abs(target)) % 2 == 1 ) return 0;
        int t = (total + abs(target) ) / 2;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1, vector<int> (t + 1, -1));
        return solve(0, t, nums, dp);
    }
};