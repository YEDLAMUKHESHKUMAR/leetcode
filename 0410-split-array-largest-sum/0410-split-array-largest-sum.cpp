class Solution {
public:
    int solve(int i, int k, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(i == n && k == 0) return 0;
        if(i >= n && k > 0) return INT_MAX;
        if(i < n && k == 0) return INT_MAX;
        if(dp[i][k] != -1) return dp[i][k];
        int sum = 0;
        int curAns = INT_MAX;
        for(int ind = i; ind < n ; ind++ ){
            sum += nums[ind];

            int nextSum = solve(ind + 1, k - 1, nums, dp);

            curAns = min(curAns, max(sum, nextSum));
        }
        return dp[i][k] = curAns;



    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        // int ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
        return solve(0, k, nums , dp);
    }
};