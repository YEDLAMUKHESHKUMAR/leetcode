// Last updated: 6/23/2025, 10:34:21 AM
class Solution {
public:
    int solve(int j, int prev, int m,  vector<string>& strs, vector<vector<int>>& dp){
        if(j >= m) return 0;
        if(dp[j][prev + 1] != -1) return dp[j][prev + 1];
        // int maxi = 0, mini = 25;
        bool smaller = false;
        if(prev!=-1){
            for(int i = 0; i < strs.size(); i++){
                if( j < strs[i].size() && strs[i][j] < strs[i][prev] ){
                    smaller = true;
                    break;
                }
            }
        }
        // cout<<j<<" "<<prev<<" "<<mini<<endl;
        if(smaller){
            return dp[j][prev + 1] = 1 + solve(j + 1, prev, m, strs, dp);
        }
        else{
            return dp[j][prev + 1] = min( solve(j + 1, j, m, strs, dp ), 1 + solve(j + 1, prev, m, strs, dp) );
        }
        return 0;

        
        return 0;
    }
    int minDeletionSize(vector<string>& strs) {
        int m  = 0;
        for(auto s : strs){
            m = max(m, (int)s.size());   // do this again approch wrong...think in
        } 
        vector<vector<int>> dp(m + 1, vector<int> (m + 2, -1));
        return solve(0 , -1, m, strs, dp);
    }
};