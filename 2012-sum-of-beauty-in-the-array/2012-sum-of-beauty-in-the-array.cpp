class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<bool> smaller(n,false);
        vector<bool> bigger(n,false);
        int mini=nums[n-1];
        int maxi=nums[0];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<mini){
                mini=nums[i];
                smaller[i]=true;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                bigger[i]=true;
            }
        }
        int sum=0;
        for(int i=1;i<n-1;i++){
            if(smaller[i]==true && bigger[i]==true){
                sum+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                sum+=1;
            }
        }
        return sum;
    }
};