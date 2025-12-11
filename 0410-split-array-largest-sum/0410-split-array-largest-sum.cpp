class Solution {
public:
    int isPossible(int mid, vector<int>& nums, int k){
        int n = nums.size();
        int sum = 0;
        k--;
        for(int i = 0; i < n ;i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                k--;
            }
            else sum += nums[i];
        }
        if(k < 0 ) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN , sum = 0;
        for(int i = 0; i < n ;i++){
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        int low = maxi, high = sum, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(mid, nums, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};