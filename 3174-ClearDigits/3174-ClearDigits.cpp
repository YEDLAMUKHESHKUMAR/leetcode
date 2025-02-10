class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string ans = "" ;
        int c = 0;
        for(int i = n-1; i>=0;i--){
            if(isdigit(s[i])){
                c++;
            }
            else{
                if(c > 0) c--;
                else ans+= s[i];
            }
        }  
        reverse(ans.begin() , ans.end());
        return ans;
    }
};