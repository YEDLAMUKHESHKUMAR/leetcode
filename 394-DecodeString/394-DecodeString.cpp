// Last updated: 8/21/2025, 12:46:15 PM
class Solution {
public:
    string solve(int& i, string& s){
        int n = s.size();
        string curr = "";
        int num = 0;
        for(; i < n ; i++){
            char ch = s[i];
            if(ch == '['){
                
                string str = solve(++i, s);
                for(; num > 0 ; num--){
                   curr += str;
                }
                
            }
            else if(ch >= '0' && ch <= '9'){
                num = num * 10 + ch - '0';
            }
            else if(ch == ']') return curr;
            else curr += ch;
        } 
        return curr;
        
    }
    string decodeString(string s) {
        int i = 0;
        string ans = "";
        return solve(i, s);   
    }
};