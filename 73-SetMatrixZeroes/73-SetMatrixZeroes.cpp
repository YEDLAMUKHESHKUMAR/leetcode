// Last updated: 5/21/2025, 10:30:38 AM
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool fr = false, fc = false;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m ;j++){
                if(mat[i][j] == 0){
                    if(i == 0) fr = true;
                    if(j == 0) fc = true;
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < n ;i++){
            for(int j = 1; j < m ;j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        if( fr ){
            for(int j = 0; j < m ;j++) mat[0][j] = 0;
        }
        if( fc ) {
            for(int i = 0; i < n ;i++) mat[i][0] = 0;
        }
        

    }
};