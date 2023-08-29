int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
      if(i==0 && j==0){                         // memoization :)
          return arr[0][0];
      }
      if(i<0 || j<0) return INT_MAX;          // since we want min
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      return dp[i][j]=arr[i][j]+min(solve(i-1,j,arr,dp),solve(i,j-1,arr,dp));

  
}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};