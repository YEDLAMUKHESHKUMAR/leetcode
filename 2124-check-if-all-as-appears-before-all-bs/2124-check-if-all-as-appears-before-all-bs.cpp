class Solution {
public:
    bool checkString(string s) {
        int b=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='b') b++;
            else{
                if(b>0) return false;
            }
        }
        return true;
    }
};