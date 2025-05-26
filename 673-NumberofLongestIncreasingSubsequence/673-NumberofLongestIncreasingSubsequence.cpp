// Last updated: 5/26/2025, 11:34:08 AM
class Solution {
public:
    int findLIS(vector<int> &nums, vector<int> &lis){
        int n = nums.size();
        for(int i = 0; i < n ;i++){
            if(lis.empty() || nums[i] > lis[lis.size() - 1]){
                lis.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
                *it = nums[i];
            }
        }
        return lis.size();
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        int longestLength = findLIS(nums, lis);
        cout<<longestLength<<endl;
        if(longestLength == 1) return n;
        vector<int> dp(n, 1);
        vector<int> ways(n, 1);
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            int maxLen = 0;
            int maxi = 0, way = 0;
            for(int j = 0; j < i ; j++){
                if(nums[i] > nums[j]){
                    maxLen = max(maxLen, 1 + dp[j]);
                    // if(maxLen == maxi){
                    //     way += ways[j];
                    // }
                    if(maxLen > maxi){
                        maxi = maxLen;
                        way = 0;
                        way += ways[j];
                    }
                    else if(dp[j] + 1 == maxi){
                        way += ways[j];
                    }
                }
            }
            dp[i] = max(dp[i], maxLen);
            ways[i] = max(ways[i], way);
        }
        // int ans = 0;
        for(int i = 0; i < n ;i++){
            // cout<<dp[i]<<" : "<<ways[i]<<endl;
            if(dp[i] == longestLength){
                ans += ways[i];
            }
        }
        return ans;
    }
};