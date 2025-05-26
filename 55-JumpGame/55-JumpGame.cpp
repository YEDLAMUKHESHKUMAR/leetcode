// Last updated: 5/26/2025, 10:18:47 AM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<bool> dp(n, false);
        int trueInd = n - 1;
        // dp[n - 1] = true; 
        for(int i = n - 2; i>= 0;i--){
            if(nums[i] == 0) continue;
            if(nums[i] + i >= trueInd){
                trueInd = i;  // I can reach from i to j ( i < j )
            }
        }
        if(trueInd != 0) return false;
        return true;
    }
};