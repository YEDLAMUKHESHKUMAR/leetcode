// Last updated: 8/10/2025, 9:50:43 AM
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int AND = -1;
        for(int i = 0; i < n ;i++){
            while(i != nums[i]){
                int currAnd = nums[i] & nums[nums[i]];
                AND = AND & currAnd;
                swap(nums[i], nums[nums[i]]);
            }
        }
        return AND == -1 ? 0 : AND;
    }
};