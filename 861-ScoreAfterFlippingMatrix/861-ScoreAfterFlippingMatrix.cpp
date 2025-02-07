class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> flipped(n, 0); // easy peasy
        for(int i = 0; i<n;i++){
            if(grid[i][0] == 0){
                flipped[i] = 1;
            }
        }
        int ans = n * (1 << (m - 1));
        for(int j = 1; j<m;j++){
            int z = 0 ;
            for(int i = 0; i<n;i++){
                if(flipped[i] == 1){
                    if(grid[i][j] == 1) z++;
                }
                else{
                    if(grid[i][j] == 0) z++;
                }
            }
            int maxi = max(z, n - z);
            ans += (maxi * ( 1 << (m - j - 1) ));

        }
        return ans;
    }
};