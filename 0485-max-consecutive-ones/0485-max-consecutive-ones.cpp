class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,one_count=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one_count++;
            }
            else{
                ans=max(ans,one_count);
                one_count=0;
            }
        }
        ans=max(ans,one_count);
        return ans;
    }
};