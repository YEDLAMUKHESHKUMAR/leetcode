// int solve(int i,int j,int n,vector<vector<int>> &arr,vector<vector<int>> &dp){
//     if(i==n){
//         return 0;
//     }
//     if(dp[i][j]!=-1){          // memoization :)
//         return dp[i][j];
//     }
//     int down=arr[i][j]+solve(i+1,j,n,arr,dp);
//     int down_right=arr[i][j]+solve(i+1,j+1,n,arr,dp);     
//     return dp[i][j]=min(down,down_right);
// }
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));     // tabulation :) 
        // return solve(0,0,m,triangle,dp);                     // no more recursion space
        for(int j=0;j<n;j++){
            dp[m-1][j]=triangle[m-1][j];    
        }
        // dp[0][0]=triangle[0][0];    
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int down_right=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,down_right);
            }
        }
        // int ans=INT_MAX;
        
        return dp[0][0];
    }
};