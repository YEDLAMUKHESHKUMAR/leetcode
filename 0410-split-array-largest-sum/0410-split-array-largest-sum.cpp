class Solution {
public:
    bool solve(vector<int> &nums , int k , int mid){
        int n = nums.size();
        int  maxPartitions = 1 ;
        int sum = 0 ;
        for(int i=0;i<n;i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                maxPartitions++ ;
            }
            else{
                sum+=nums[i];
            }
        }
        if(maxPartitions > k){
            return false;
        }
        return true;

    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0 ;
        int maxi = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]>maxi){
                maxi = nums[i];
            }
        }
        int ans  = 0 ;
        int low = maxi, high = sum ;
        while(low <= high){
            int mid = (low + high ) / 2 ;
            if((solve(nums,k,mid)) == true){
                ans = mid ;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};