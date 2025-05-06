// Last updated: 5/6/2025, 11:15:38 AM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n ;i++){
            int element = nums[nums[i]];
            if(element >= n){
                element = element % n;
            }
            nums[i] = n * element + nums[i];
        }
        for(int i = 0; i < n ;i++){
            nums[i] = nums[i] / n;
        }
        return nums;
    }
};