class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int n=nums.size();
        ans=sum;
        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            // ans=max(ans,sum/k);
            ans=max(ans,sum);
        }
        ans=max(ans,sum);
        return ans/k;

    }
};