int solve(int i,int j1,int j2,int m,int n,vector<vector<int>>& arr,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>=n || j2<0 || j2>=n){
        return -1e8;
    }
    if(i==m-1){
        if(j1==j2){                                         // memoization will work
            return arr[i][j1];
        }
        else{
            return arr[i][j1]+arr[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int maxi=-1e8;
    for(int g1=-1;g1<=+1;g1++){
        for(int g2=-1;g2<=+1;g2++){
            int value=0;
            if(j1==j2){
                value=arr[i][j1];
            }
            else{
                value=arr[i][j1]+arr[i][j2];
            }
            value+=solve(i+1,j1+g1,j2+g2,m,n,arr,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (n,-1)));
        return solve(0,0,n-1,m,n,grid,dp);
    }
};