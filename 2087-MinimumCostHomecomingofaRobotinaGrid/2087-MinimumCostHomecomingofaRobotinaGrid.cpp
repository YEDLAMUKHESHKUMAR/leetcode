// Last updated: 7/12/2025, 9:16:33 PM
class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int food = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == 'H'){
                if(i > 0 && s[i - 1] == 'F') continue;
                if(i < n && s[i + 1] == '.') {
                    food++;
                    s[i + 1] = 'F';
                } 
                else if(i > 0 && s[i - 1] == '.'){
                    food++;
                }
                else return -1;

            }
        }
        return food;
    }
};