// int solve(int i,int j,int m,int n,vector<vector<int>> &dp){
//     if(i==m-1 && j==n-1){
//         return 1;
//     }
//     if(i>m-1 || j>n-1){               // memoization will work
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int right=solve(i,j+1,m,n,dp);
//     int down=solve(i+1,j,m,n,dp);
//     return dp[i][j]=right+down;
// }
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            int up=0;
            int left=0;
            for(int j=0;j<n;j++){        // tabulation 
                if(j>0) left=dp[i][j-1]; 
                up=dp[i-1][j];
                dp[i][j]=up+left;
            }

        }
        return dp[m-1][n-1];
        // return solve(0,0,m,n,dp);
    }
};