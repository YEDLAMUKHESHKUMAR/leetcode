// Last updated: 4/6/2025, 6:06:12 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n + 1, 1);
        vector<int> indexes(n + 1, -1);
        indexes[0] = -1;
        int backTrackIndex = 0, maxi = 0;
        for(int i = 1; i < n;i++){
            for(int j = 0; j < i ; j++){
                if(nums[i] % nums[j] == 0){
                    if( dp[j] + 1 > dp[i] ){
                        indexes[i] = j;
                        dp[i] = 1 + dp[j];
                    }
                }
            }
            cout<<dp[i] << " : "<<backTrackIndex<<endl;
            if(dp[i] > maxi){
                maxi = dp[i];
                backTrackIndex = i;
            }
        }
        
        vector<int> ans;
        while(backTrackIndex != -1){
            ans.push_back(nums[backTrackIndex]);
            backTrackIndex = indexes[backTrackIndex];
            
        }
        return ans;
    }
};