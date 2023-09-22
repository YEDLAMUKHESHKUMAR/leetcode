class Solution {
public:
    bool checkRecord(string s) {
        int isabsent=0,islate=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                isabsent++;
                islate=0;
                if(isabsent>=2) return false;
            }
            else if(s[i]=='L'){
                islate++;
                if(islate>=3){
                    return false;
                }
            }
            else{
                islate=0;
            }
        }
        return true;
    }
};