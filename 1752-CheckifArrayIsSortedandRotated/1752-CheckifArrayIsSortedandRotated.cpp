class Solution {
public:
    bool check(vector<int>& nums) {
        int decrease_count=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                decrease_count++;
            }
            if(decrease_count>1){
                return false;
            }

        }
        if(nums[n-1]>nums[0] && decrease_count==1){
            return false;
        }
        return true;
    }
};