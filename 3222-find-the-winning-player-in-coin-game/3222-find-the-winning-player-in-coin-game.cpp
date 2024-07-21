class Solution {
public:
    string losingPlayer(int x, int y) {

        int c = 0;
        while(true){
            if(x  <  1 || y  < 4 ) {
                break;
            }
            x--;
            y-=4;
            c++;
        }
        if(c%2==0){
            return "Bob";
        }
        return "Alice";
    }
};