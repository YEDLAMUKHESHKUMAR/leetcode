class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;    // brilliant solution 
        int n=nums.size();
        int currSum=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
       for(int left=0,right=0;right<n;right++){
            currSum+=nums[right];
            while(left<=right && currSum >sum-x) currSum-=nums[left++];
            if(currSum==sum-x) maxi=max(maxi,right-left+1); 
        
        }
        return maxi== -1?-1:n-maxi;

    }
};