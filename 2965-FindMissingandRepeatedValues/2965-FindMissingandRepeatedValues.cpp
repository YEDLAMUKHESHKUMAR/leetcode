class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        int ans1,ans2;
        int n = grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j = 0 ;j<grid[i].size();j++){
                mp[grid[i][j]]++;
                if(mp[grid[i][j]]==2) ans1 = grid[i][j];
            }
            
        }
        for(int i=1;i<=n*n;i++){
            if(mp[i]==0) {
                ans2 = i ;
                break;
            }
        }
        return {ans1,ans2};
    }
};