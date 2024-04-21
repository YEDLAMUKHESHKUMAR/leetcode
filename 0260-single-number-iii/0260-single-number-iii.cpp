class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long Xor = 0; 
        for(int i = 0;i<n;i++){
            Xor ^= nums[i];  
        }
        long rightMostSetBit = (Xor ^ (Xor & (Xor - 1))); 


        int bucket1 = 0 ,bucket2 = 0 ;
        // return {ind,ind};
        for(int i = 0;i <n;i++){
            if(nums[i] & rightMostSetBit ){ // if nums[i] is set like  rightMostSetBit then bucket1 holds it
                bucket1 = bucket1 ^ nums[i];
            }
            else{
                bucket2 = bucket2 ^ nums[i];
            }
        }
        return {bucket1,bucket2};

    }
};