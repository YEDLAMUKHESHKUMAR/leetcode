// Last updated: 4/18/2025, 11:15:51 AM
class Solution {
public:
    string solve(string &s){
        string ans = "";
        int n = s.size(), c = 0, i = 0;
        char ch = s[0];
        while(i < n ){
            while(i < n && s[i] == ch){
                c++; i++;
            }
            ans += to_string(c);
            ans += ch;
            if(i < n ) ch = s[i];
            c = 0;
        }
        return ans;
    }
    string countAndSay(int n) {
        string s = "1";
        if(n == 1) return s;
        for(int i = 0; i < n - 1; i++){
            string temp = solve(s);
            s = temp;
        }
        return s;
    }
};