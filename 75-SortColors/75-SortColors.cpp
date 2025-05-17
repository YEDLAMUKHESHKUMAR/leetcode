// Last updated: 5/17/2025, 1:17:57 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z = 0 , o = 0 , t = 0;
        int n = nums.size();
        for(int i= 0;i<n;i++){
            if(nums[i] == 0) z++;
            else if(nums[i] == 1 ) o++;
            else t++;
        }
        int ind = 0;
        for(int i = 0 ;i<z;i++){
            nums[ind++] = 0;
        }
        for(int i = 0 ;i<o;i++){
            nums[ind++] = 1;
        }
        for(int i = 0 ;i<t;i++){
            nums[ind++] = 2;
        }
    }

};