class Solution {
public:
    int solve(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=c || j2<0 || j2>=c){
            return -1e8;
        }
        if(i==r-1){
            if(j1==j2){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        int maxi = -1e8;
        for(int g1 = -1 ; g1<= +1 ; g1++){
            for(int g2 = -1; g2<=+1;g2++){
                int val = 0;
                if(j1==j2){
                    val = grid[i][j1];
                }
                else{
                    val = grid[i][j1] + grid[i][j2];
                }
                val+= solve(i+1,j1+g1,j2+g2,r,c,grid,dp);
                maxi =  max(maxi,val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size(); 
        vector<vector<vector<int>>> dp(row,vector<vector<int>> (col,vector<int> (col,-1)));
        return solve(0,0,col-1,row,col,grid,dp);
    }
};