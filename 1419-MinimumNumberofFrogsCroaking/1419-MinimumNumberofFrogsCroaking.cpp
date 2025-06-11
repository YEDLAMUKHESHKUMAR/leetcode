// Last updated: 6/11/2025, 11:46:53 PM
class Solution {
public:
    int minNumberOfFrogs(string s) {
        int n = s.size();
        int ans = 0;
        int speak = 0;
        // vector<int> mp(26, 0);
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        for(int i = 0; i < n ;i++){
            if(s[i] == 'c'){
                speak++;
                c++;
                ans = max(ans, speak);
            }
            else if(s[i] == 'k'){
                c--; r--; o--; a--;
                if(c < 0 || r < 0 || o < 0 || a < 0) return -1;
                speak--;
            }
            else if(s[i] == 'r'){
                r++;
                if(c < r) return -1;
            }
            else if(s[i] == 'o'){
                o++;
                if(c < o || r < o ) return -1;
            }
            else if(s[i] = 'a'){
                a++;
                if(c < a || r < a ||  o < a) return -1;
            }
        }
        if(c != 0 || r != 0 || o != 0 || a != 0 || k != 0) return -1;
        return ans;
    }
};