class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;i++){
            string sub= s.substr(0,i);
            string repeating="";
            for(int j=0;j<n/i;j++){
                repeating+=sub;
            }
            if(repeating==s) return true;
        }
        return false;
    }
};