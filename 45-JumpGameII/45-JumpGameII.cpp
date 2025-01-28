class Solution {
public:
    // int ans  = n;
    int solve(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(i >= n-1){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = 1e8;
        for(int ind = 1; ind <= nums[i] ;ind++){
            ans = min(ans, 1 + solve(ind + i, nums, dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);


    }
};