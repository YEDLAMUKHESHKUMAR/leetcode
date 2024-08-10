class Solution {
public: 
    void dfs(int i,int j,vector<vector<int>> &mat){
        int n = mat.size();
        if(i<0 || i>=n || j<0 || j>=n || mat[i][j] == 1){
            return;
        }
        mat[i][j] = 1;
        dfs(i+1,j,mat);
        dfs(i-1,j,mat);
        dfs(i,j+1,mat);
        dfs(i,j-1,mat);

    }
    int isLandCount(vector<vector<int>> &mat){
        int size = mat.size();
        int ans= 0;
        for(int i = 0;i<size;i++){
            for(int j = 0;j<size;j++){
                if(mat[i][j] == 0){
                    dfs(i,j,mat);
                    ans++;
                }
            }
        }
        return ans;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n*3,vector<int> (n*3,0));
        int row = 0;
        for(int i = 0;i<n;i++){
            int col = 0;
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] ==' '){
                    col+=3;
                    continue;
                }
                else if(grid[i][j] == '/'){
                    mat[row][col+2] = 1;
                    mat[row+1][col+1] = 1;
                    mat[row+2][col] = 1;
                }
                else{
                    // mat[row][col] = 1;
                    // mat[row+1][col+1] = 1 ; 
                    mat[row][col] = 1;
                    mat[row+1][col+1] = 1;
                    mat[row+2][col+2] = 1;
                }
                col+=3;
            }
            row+=3;
        }
        for(int i = 0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }


        return isLandCount(mat);        
    }
};