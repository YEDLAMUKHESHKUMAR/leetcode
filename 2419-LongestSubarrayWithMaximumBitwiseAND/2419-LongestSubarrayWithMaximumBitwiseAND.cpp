// Last updated: 7/30/2025, 6:48:19 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // notes :)
        int AND = nums[0];
        int maxAND = nums[0];
        for(int i = 0; i < n ;i++){
            AND &= nums[i];
            if(AND < nums[i]){
                maxAND = max(maxAND, nums[i]);
                AND = nums[i];
            }
            // maxi = max(maxi, nums[i]);
        }
        int maxCount = 0, c = 0;
        for(int i = 0 ; i < n ;i++){
            if(nums[i] == maxAND) c++;
            else {
                maxCount = max(maxCount, c);
                c = 0;
            } 
        }
        maxCount = max(maxCount, c);
        return maxCount;
    }
};