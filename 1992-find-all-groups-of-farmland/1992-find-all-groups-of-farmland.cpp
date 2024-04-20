class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size(); // notes 
        vector<vector<int>> ans;
        
        for (int row1 = 0; row1 < m; row1++) {
            for (int col1 = 0; col1 < n; col1++) { //:)
                if (land[row1][col1]) {
                    int x = row1, y = col1;
                    
                    for (x = row1; x < m && land[x][col1] == 1; x++) {
                        for (y = col1; y < n && land[x][y] == 1; y++) {
                            land[x][y] = 0;
                        }
                    }

                    ans.push_back({row1, col1, x - 1, y - 1});
                }
            }
        }
        return ans;
    }
};