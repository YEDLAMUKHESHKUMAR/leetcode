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
        vector<int> next(n,0);     // tabulation :) 
        // return solve(0,0,m,triangle,dp);                     // space optimization
        for(int j=0;j<n;j++){
            next[j]=triangle[m-1][j];    
        }
        // dp[0][0]=triangle[0][0];    
        for(int i=m-2;i>=0;i--){
            n=triangle[i].size();
            vector<int> curr(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+next[j];
                int down_right=triangle[i][j]+next[j+1];
                curr[j]=min(down,down_right);
            }
            next=curr;
        }
        // int ans=INT_MAX;
        
        return next[0];
    }
};