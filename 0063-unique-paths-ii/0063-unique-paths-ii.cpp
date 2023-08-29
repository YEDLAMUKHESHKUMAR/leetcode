// int solve(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
//     if(i==0 && j==0){
//         return 1;
//     }  
//     if(i<0 || j<0 || arr[i][j]==1){             //  memoization .......will work
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int left=solve(i,j-1,arr,dp);
//     int up=solve(i-1,j,arr,dp);
//     return dp[i][j]=left+up;
// }
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;                // tabulation .......will work
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++){
            int left=0,up=0;
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }

        }
        return dp[m-1][n-1];
        // return solve(m-1,n-1,obstacleGrid,dp);
    }
};