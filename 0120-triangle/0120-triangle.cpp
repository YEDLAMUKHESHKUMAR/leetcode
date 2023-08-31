int solve(int i,int j,int n,vector<vector<int>> &arr,vector<vector<int>> &dp){
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=arr[i][j]+solve(i+1,j,n,arr,dp);
    int down_right=arr[i][j]+solve(i+1,j+1,n,arr,dp);     // recursion ...will give TLE :)
    return dp[i][j]=min(down,down_right);
}
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(0,0,m,triangle,dp);
    }
};