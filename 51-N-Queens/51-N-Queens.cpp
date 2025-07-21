// Last updated: 7/21/2025, 9:58:46 PM
class Solution {
public:
    bool isValid(int row, int col, vector<int>& pos){
        for(int i = 0 ; i< pos.size(); i++){
            int r = i, c = pos[i];
            if(c == col) return false;
            if(abs(row - r) == abs(col - c)) return false;
        }
        return true;
    }
    void solve(int row, int n, vector<string>& board, vector<int> pos, vector<vector<string>>& ans){
        if(row >= n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n ;j++){
            if(isValid(row, j, pos)){
                board[row][j] = 'Q';
                pos.push_back(j);
                solve(row + 1, n, board, pos, ans);
                pos.pop_back();
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> pos;
        solve(0, n, board, pos, ans);
        return ans;
    }
};