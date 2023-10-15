class Solution {
public:
    bool isValid(int row,int col,int n,vector<string> &board){
        int dupRow=row;
        int dupCol = col;
        while(dupCol>=0){
            if(board[row][dupCol]=='Q') return false;
            dupCol--;
        }
        dupCol = col;
        while(dupRow>=0 && dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupCol--;
            dupRow--;
        }
        // dupCol = col;
        // dupRow = row;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }        
        return true;
    }
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,n,board)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,board,ans);
        return ans;

    }
};