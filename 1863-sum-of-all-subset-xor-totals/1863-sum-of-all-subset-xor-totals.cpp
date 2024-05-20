class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int size = (int)(pow(2,n));  // :) 
        int ans = 0;
        for(int  i = 0;i<size;i++){
            int tempXor = 0 ;
            int bitNumber = i ;
            for(int j = 0;j<31;j++){
                if((bitNumber >> j ) & 1 == 1) tempXor ^= nums[j];
            }
            ans+=tempXor;
        }
        return ans;

    }
};