// int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
//       if(i==0 && j==0){                         // memoization :)
//           return arr[0][0];
//       }
//       if(i<0 || j<0) return INT_MAX;          // since we want min
//       if(dp[i][j]!=-1){
//           return dp[i][j];
//       }
//       return dp[i][j]=arr[i][j]+min(solve(i-1,j,arr,dp),solve(i,j-1,arr,dp));

  
// }
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));       // tabulation :)
        
        for(int i=0;i<m;i++){
            int left=INT_MAX;
            int up=INT_MAX;
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[0][0];
                    continue;
                }
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,left);
            }
        }
        return dp[m-1][n-1];
        // return solve(m-1,n-1,grid,dp);
    }
};