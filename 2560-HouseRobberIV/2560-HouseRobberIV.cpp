class Solution {
public:
    int solve(int CanBeMin, vector<int> &nums, unordered_map<int,vector<int>> &mp, int k){
        int n = nums.size();
        vector<int> vis(n,0);
        int taken = 0, foundMin = false;
        for(int i = 0; i< n;i++){
            if(i == 0 && nums[i] <= CanBeMin) {
                taken++;
                vis[0] = 1;
                if(nums[i] == CanBeMin) foundMin = true;
            }
            else{
                if(nums[i] <= CanBeMin && vis[i - 1] == 0){
                    vis[i] = 1;
                    taken++;
                    if(nums[i] == CanBeMin) foundMin = true;
                }
            }
        }
        if(taken < k) return false;
        return true;
        // no need to check whether mid exist or not... since there exists >=k elements...this can be our answer...so assume it is our answer and return true...
        
        
    }

    int minCapability(vector<int>& nums, int k) {
        // 2 3 2 1 3 9 9
        int n = nums.size();
        unordered_map<int,vector<int>> mp;  // no use of map...
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n ;i++){
            mp[nums[i]].push_back(i);
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        int low = mini, high = maxi, ans = -1;
        while(low <= high){
            int mid = (low + high ) / 2;
            if(solve(mid, nums, mp, k)){
                ans = mid; // check this out... don't store waste values...
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};