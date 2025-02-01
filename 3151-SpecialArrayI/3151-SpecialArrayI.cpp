class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        int e = 0,o= 0;
        for(int i = 1;i<n;i++){
            if(nums[i] % 2 == 0 && nums[i-1] % 2 == 0) return false;
            if(nums[i] % 2 != 0 && nums[i-1] % 2 != 0) return false;
        }
        return true;
        
    }
};