class Solution {
public:
    int BS(vector<int> &nums){
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] <= 0){
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans == -1 ? 0 : n - ans;
    }


    int BS2(vector<int> &nums){
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= 0){
                high = mid - 1;
            }
            else {
                ans = mid;
                low = mid  + 1 ; 
            }
        }
        return ans == -1 ? 0 : ans + 1;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int positiveElements = BS(nums);
        int negativeElements = BS2(nums);
        return max(positiveElements, negativeElements); 
    }
};