// Last updated: 5/7/2025, 12:23:10 PM
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int ans = 1;
        // dp[i] --> tells me the longest chain till index i.
        for(int i = 0; i < n ; i++){
            int chain = 1;
            for(int j = 0 ; j < i; j++ ){
                if(pairs[i][0] > pairs[j][1]){
                    chain = max(chain , 1 + dp[j] );
                }
            }
            dp[i] = chain;
            ans = max(ans, chain);
        }        
        return ans;
    }

};