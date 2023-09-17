class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        
        int i=0,j=1;
        int minOperations=0;
        while(i<n && j<n){
            if(nums[i]==nums[j]){
                j++;
                minOperations++;
            }
            else{
                i=j+1;
                j=i+1;
            }
        }
        n=n-minOperations;
        if(n%2!=0){
            minOperations++;
        }
        return minOperations;
    }
};