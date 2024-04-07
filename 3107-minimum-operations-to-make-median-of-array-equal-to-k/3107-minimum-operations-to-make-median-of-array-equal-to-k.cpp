class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        // 1 2
        // 2 5 6 8 6 5 8 8
        // 2 5 5 6 1 8 8 8
        int n = nums.size();
        sort(nums.begin(),nums.end());   // done in contest :) , but not submitted (due to late comer)
        long long start = n / 2;
        long long op = abs(nums[start] - k) ;
        
        for(long long i = start + 1 ; i<n;i++){
            if(nums[i] < k){
                op+=abs(k-nums[i]);
            }
            else break;
        }
        for(long long i = start -1 ;i>=0;i--){
            if(nums[i] > k){
                op+=abs(k - nums[i]);
            }
            else break;
        }
        return op;
        
    }
};