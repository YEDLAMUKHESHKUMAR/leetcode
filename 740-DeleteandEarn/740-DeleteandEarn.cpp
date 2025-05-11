// Last updated: 5/11/2025, 11:19:40 PM
class Solution {
public:
    // int solve(int i, int prev, vector<int> &nums, unordered_map<int,int> &mp, vector<vector<int>> &dp){
    //     int n = nums.size();
    //     if(i >= n) return 0;
    //     if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
    //     int pick = 0;
    //     if(prev == -1 || nums[prev] + 1 != nums[i]){
    //         pick = nums[i] * mp[nums[i]] + solve(i + 1, i, nums, mp, dp);
    //     }
    //     int notPick = solve(i + 1, prev, nums, mp , dp);
    //     return dp[i][prev + 1] = max(pick , notPick);
    // }
    int deleteAndEarn(vector<int>& nums) {
        // 2 3 5 6 7 9 11 13
        int n = nums.size();
        unordered_map<int,int> mp;
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1,  -1));
        vector<int> arr;
        int maxi = 0;
        for(int i = 0; i < n ;i++){
            mp[nums[i]]++;
            maxi = max(maxi, nums[i]);
            if(mp[nums[i]] == 1) arr.push_back(nums[i]);
        }
        sort(arr.begin(), arr.end());
        // return solve(0, -1, arr, mp , dp);
        vector<int> dp(maxi + 1, 0);
        dp[1] = mp[1];
        for(int i = 2 ;i<= maxi;i++){
            dp[i] = max(dp[i - 1], mp[i] * i + dp[i - 2]);
        }
        return dp[maxi];

        
    }
};