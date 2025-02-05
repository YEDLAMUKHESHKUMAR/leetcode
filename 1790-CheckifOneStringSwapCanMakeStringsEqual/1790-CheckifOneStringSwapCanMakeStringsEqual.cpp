class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n != m) return false;
        bool noMismatch = true;
        int ind = -1;
        for(int i = 0; i<n;i++){
            if(s1[i] != s2[i]){
                if(noMismatch == true) {
                    noMismatch = false;
                    ind = i;
                }
                else{
                    swap(s1[i], s1[ind]);
                    if(s1[i] != s2[i] || s1[ind] != s2[ind]) return false;
                    break;
                }
            }
        }
        if(noMismatch == false){
            for(int i = 0; i<n;i++) {
                if(s1[i] != s2[i]) return false;
            }
        }
        return true;
    }
};