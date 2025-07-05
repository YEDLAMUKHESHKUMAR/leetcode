// Last updated: 7/5/2025, 10:25:57 AM
class Solution {
public:
    vector<int> row = {0, -1, 0, 1};
    vector<int> col = {-1, 0, 1, 0};
    void solve(int i, int j, int parent, int& ones, vector<vector<int>>& grid, vector<vector<int>>& vis ){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = parent;
        ones++;
        for(int k = 0 ; k < 4 ; k++){
            int newRow = i + row[k];
            int newCol = j + col[k];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !vis[newRow][newCol] ){
                solve(newRow, newCol, parent, ones, grid, vis);
            }

        }
    }
    int getSurroundings(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, unordered_map<int,int>& grpSize){
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int,int> mp;
        int ones = 1;
        for(int k = 0; k < 4; k++){
            int newRow = i + row[k];
            int newCol = j + col[k];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 ){
                mp[ vis[newRow][newCol] ]++;
            }
        }
        for(auto k : mp){
            ones += (grpSize[k.first]);
        }
        return ones;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n + 1, vector<int> (m + 1, 0));
        unordered_map<int, int> grpSize;
        int largestIsland = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ;j++){
                if( grid[i][j] == 1 && !vis[i][j] ){
                    int ones = 0, parent = i * m + j + 1 ;
                    solve(i, j,  parent , ones, grid, vis );
                    largestIsland = max(largestIsland, ones);
                    grpSize[parent] = ones; 
                }
            }
        }
        for(int i = 0 ;i < n ;i++){
            for(int j = 0; j < m ;j++ ){
                if(grid[i][j] == 0){
                    largestIsland = max(largestIsland,  getSurroundings( i, j, grid, vis, grpSize) );
                }
            }
        }
        return largestIsland;
    }
};