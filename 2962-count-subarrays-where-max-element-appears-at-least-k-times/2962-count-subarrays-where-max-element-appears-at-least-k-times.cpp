class Solution {
public:
    long long atMost(vector<int> &nums,int k){
        long long maxi = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            // maxi = max(maxi,nums[i]);
            if(nums[i] > maxi) maxi = nums[i];
        }
        int j = 0;
        long long maxCount = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == maxi) maxCount++;
            while(j<n && maxCount > k){
                if(nums[j] == maxi) maxCount--;
                j++;
            }
            ans += i-j+1;
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        return (n*(n+1)/2) - atMost(nums,k-1);
         
    }
};