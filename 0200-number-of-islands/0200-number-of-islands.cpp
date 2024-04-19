class Solution {
public:
void solve(vector<vector<char>>& grid,int i,int j){
    int m = grid.size();
        int n = grid[0].size();
    if(i < 0  || i==m || j==n || j<0 || grid[i][j] == '0'){
        return;
    }
    grid[i][j]='0';
    solve(grid, i - 1, j);
    solve(grid, i + 1, j);
    solve(grid, i, j - 1);
    solve(grid, i, j + 1);

}
    int numIslands(vector<vector<char>>& grid) {
        // notes
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){

                ans++;
                solve(grid,i,j);
                }
            }
        }
        return ans;
    }
};