class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,int> minRow;
        unordered_map<int,int> maxCol;
        for(int i = 0 ;i<n;i++){   
            int mini = INT_MAX;
            for(int j = 0;j<m;j++){
                mini = min(mini,mat[i][j]);
            }
            minRow[mini]++;
        }
        for(int i = 0 ;i<m;i++){
            int maxi = INT_MIN;
            for(int j = 0;j<n;j++){
                maxi = max(maxi,mat[j][i]);   
            }
            maxCol[maxi]++;
        }
        for(auto i : minRow){
            if(maxCol[i.first] > 0 ){
                return {i.first};
            }
        }
        return {};
    }
};