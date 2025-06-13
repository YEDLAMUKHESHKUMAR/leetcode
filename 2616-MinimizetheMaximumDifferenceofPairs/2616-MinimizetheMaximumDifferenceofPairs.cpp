// Last updated: 6/13/2025, 5:43:40 PM
class Solution {
public:
    bool solve(int maxDiff, vector<int>& nums, int p){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] <= maxDiff){
                i++;
                p--;
            }
            if(p <= 0 ) break;
        }
        return p <= 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        // 1 1 2 3 7 10
        int n = nums.size();
        if(p == 0 || n == 1) return 0;
        // if(n == 1) 
        sort(nums.begin(), nums.end());
        int low = 0, high =  nums[n - 1] - nums[0];
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(mid, nums, p)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};