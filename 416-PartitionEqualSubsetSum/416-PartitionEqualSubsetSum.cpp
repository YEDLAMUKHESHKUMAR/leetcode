// Last updated: 4/7/2025, 5:17:40 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        sum /= 2;
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        for(int i = 0; i < n;i++) dp[i][0] = 1;
        for(int i = 1 ; i <= n;i++){
            for(int j = 0; j <= sum; j++){
                bool take , notTake = dp[i-1][j];
                if(nums[i-1] <= j){
                    take = dp[i - 1 ][ j - nums[i-1] ];
                }
                dp[i][j] = take | notTake;
            }
        }
    return dp[n][sum];
        

    }
};