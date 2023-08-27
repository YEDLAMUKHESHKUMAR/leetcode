class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        for(char i:moves){
            if(i=='R') x++;
            else if(i=='L') x--;
            else if(i=='U') y++;
            else y--;
        }
        if(x==0 && y==0) return true;
        return false;
        // int n=moves.size();
        // int right=0,left=0;
        // int up=0,down=0;
        // for(int i=0;i<n;i++){       why this is not working ???
        //     if(moves[i]=='R') right++;
        //     else if(moves[i]='L') left++;
        //     else if(moves[i]=='U') up++;
        //     else down++;
        // }
        // if(left==right && up==down) return true;
        // else return false;
    }
};