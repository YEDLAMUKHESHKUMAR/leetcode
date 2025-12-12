class Solution {
public:
    int solve(int i, int numSlots, vector<int>& nums, map<vector<int>, int>& dp, vector<int>& count){
        int n = nums.size();
        if(i >= n){
           return 0;
        }
        if(dp.find(count) != dp.end()) return dp[count];

        int ans = -1;
        for(int slot = 1; slot <= numSlots; slot++){
            if(count[slot] < 2){
                count[slot]++;
                int res = (slot & nums[i]) + solve(i + 1, numSlots, nums, dp, count);
                count[slot]--;
                ans = max(ans, res);
            }

        }
        return dp[count] = ans;

        

    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int maxSum = 0;
        vector<int> count(numSlots + 1, 0);
        map<vector<int>, int> dp;

        return solve(0, numSlots, nums, dp, count);
        // return maxSum;
    }
};