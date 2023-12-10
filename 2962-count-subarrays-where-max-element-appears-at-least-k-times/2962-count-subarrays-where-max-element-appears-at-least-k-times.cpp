class Solution {
public:
    long long atmost(vector<int> &nums,int k){
        long long maxi = *max_element(nums.begin(),nums.end());  // :) 
        int n = nums.size();
        int j = 0;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == maxi ) {
                k--;
            }
            while(k<0){
                if(nums[j] == maxi){
                    k++;
                }
                j++;
            }
            ans+=(i - j  + 1 );
            
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        return (n*(n+1))/2 - atmost(nums,k-1);
    }
};