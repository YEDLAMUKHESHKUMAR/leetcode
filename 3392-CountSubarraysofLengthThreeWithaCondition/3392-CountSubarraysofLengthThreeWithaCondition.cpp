// Last updated: 4/27/2025, 1:37:09 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int i = 2 ;i<n;i++){
            int parSum = nums[i] + nums[i-2];
            if(nums[i-1] % 2 == 1) continue;
            if(parSum * 2 == nums[i-1]) ans++;
        }
        return ans;
    }
};