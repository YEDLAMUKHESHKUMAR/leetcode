// Last updated: 8/12/2025, 10:23:35 AM
class Solution {
public:
    int mod = 1000000007;
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size() ) {
            if(target == 0 ) return 1;
            return 0;
        }
        if(target == 0) return 1;
        if(dp[i][target] != -1) return dp[i][target];
        int take = 0;
        if(nums[i] <= target){
            take = solve(i + 1, target - nums[i], nums, dp);
        }
        int notTake = solve(i + 1, target, nums, dp);
        return dp[i][target] = ((take % mod) + (notTake % mod)) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<int> nums;
        int st = 1;
        while(true){
            int temp = (int)pow(st, x);
            if(temp > n ) break;
            nums.push_back(temp);
            // cout<<nums.back()<<" ";
            st++;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int> (n + 1 , -1));
        return solve(0, n, nums, dp);
        

    }
};