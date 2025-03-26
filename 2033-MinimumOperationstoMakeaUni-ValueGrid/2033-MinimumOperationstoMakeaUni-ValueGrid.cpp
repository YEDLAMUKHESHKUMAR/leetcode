// Last updated: 3/26/2025, 10:15:07 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // 2 2 4 6 8 8 10
        vector<int> allElements; 
        int n = grid.size();
        int m = grid[0].size(), op = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0 ; j < m ;j++){
                allElements.push_back(grid[i][j]);
            }
        }
        sort(allElements.begin(), allElements.end());
        int sz = allElements.size();
        for(int i = 1; i < sz;i++ ){
            if( (allElements[i] - allElements[i-1]) % x != 0 ){
                return -1;
            }
        }
        int makeThemEqualTo = allElements[sz / 2]; // it is same as.. making every element equal to middle element...in case of duplicates, we just make them equal to most freq element
        for(int i = 0; i < sz; i++){
            op += (abs(allElements[i] - makeThemEqualTo) / x);
        }
        return op;

    }
};