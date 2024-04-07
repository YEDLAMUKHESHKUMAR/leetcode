class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        int op = 0;
        for(int i = 0;i<n;i++){
            for(int j = 'a';j<='z';j++){        // done in contest , but not submitted (due to late comer)
                int nd = abs((s[i] - 'a') - (j - 'a'));
                // if(nd == 26) return "sd"; // i wrote this for debugging in contest
                int xd = abs((s[i]-'a') - ('z'-'a')) + 1  ;  
                int d = abs(('a'-'a') -( j-'a'));
                int minDiff = min(d+xd,nd);
                if(k-minDiff >= 0){
                    s[i] = j;
                    k-=minDiff;
                    break;
                }
            }
        }
        return s;
    }
};