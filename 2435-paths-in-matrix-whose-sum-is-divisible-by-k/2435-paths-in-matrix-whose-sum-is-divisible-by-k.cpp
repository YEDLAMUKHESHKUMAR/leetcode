class Solution {
public: 
    int mod = 1e9 + 7;
    int solve(int i, int j, int sum, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){

        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m ) return 0;
        sum = (sum +  grid[i][j]) % k;
        if(i == n - 1 && j == m - 1){
            
            if(sum == 0) return 1;
            return 0;
        }
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        int right = solve(i, j + 1, sum, k, grid, dp );
        int down = solve(i + 1, j , sum, k, grid, dp );
        return dp[i][j][sum] = (right + down) % mod;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> ( k + 1, -1)));
        return solve(0, 0, 0, k, grid, dp);
    }
};