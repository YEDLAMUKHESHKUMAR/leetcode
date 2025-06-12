// Last updated: 6/12/2025, 3:48:42 PM


class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = abs(nums[n-1] - nums[0]);
        for(int i = 1; i<n;i++){
            maxi = max(maxi, abs(nums[i] - nums[i-1]));
        }
        return maxi;
    }
};