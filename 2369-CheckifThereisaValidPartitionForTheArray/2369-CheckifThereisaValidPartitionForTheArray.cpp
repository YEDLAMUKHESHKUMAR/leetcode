// Last updated: 6/3/2025, 2:14:50 PM
class Solution {
public:
    bool solve(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(i >= n) return true;
        if(dp[i] != -1) return dp[i];
        bool twoTake = false, threeTake = false;;
        if(i + 1 < n){
            if(nums[i] == nums[i + 1]) {
                twoTake = solve(i + 2, nums, dp);
            }
        }
        if(i + 2 < n){
            if(nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]){
                threeTake = solve(i + 3, nums, dp);
            }
            else if(nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1){
                threeTake = solve(i + 3, nums, dp);
            }
        }
        return dp[i] = twoTake | threeTake;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};