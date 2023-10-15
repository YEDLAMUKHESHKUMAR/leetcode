class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>> &board, string &word,int ind){
        if(ind==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[ind]){
            return false;
        }
        char temp = board[i][j];
        board[i][j]='*';
        int up = isValid(i-1,j,board,word,ind+1);
        int left = isValid(i,j-1,board,word,ind+1);
        int down = isValid(i+1,j,board,word,ind+1);
        int right = isValid(i,j+1,board,word,ind+1);
        board[i][j]= temp;
        return up || left || down || right ;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isValid(i,j,board,word,0)==true){
                    return true;
                }
            }
        }
        return false;
    }
};