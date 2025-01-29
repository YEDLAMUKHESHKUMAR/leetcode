class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // state : LIS till i, having the number Ai at last ...
        // transition : we check for all the numbers previous to Ai, (already calculate LIS to every j < i)
        vector<int> dp(n, 1); // 1 because, the number it self is LIS
        int maxLis = 1;
        for(int i = 0; i< n ;i++){
            for(int j = 0 ;j <i ;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLis = max(maxLis , dp[i]);
        }
        // for(auto i:dp) cout<<i<<" ";
        return maxLis;

    }
};