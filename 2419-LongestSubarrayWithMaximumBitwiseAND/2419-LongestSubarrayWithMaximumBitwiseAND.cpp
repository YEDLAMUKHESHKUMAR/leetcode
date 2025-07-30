// Last updated: 7/30/2025, 6:42:34 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // notes :)
        int maxi = 0;
        for(int i = 0; i < n ;i++){
            maxi = max(maxi, nums[i]);
        }
        int maxCount = 0, c = 0;
        for(int i = 0 ; i < n ;i++){
            if(nums[i] == maxi) c++;
            else {
                maxCount = max(maxCount, c);
                c = 0;
            } 
        }
        maxCount = max(maxCount, c);
        return maxCount;
    }
};