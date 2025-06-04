// Last updated: 6/4/2025, 10:02:35 AM
class Solution {
public:
    string answerString(string s, int numFriends) {
        int n = s.size();
        if(numFriends == 1) return s;
        char ch = 'a';
        for(int i = 0 ; i < n;i++){
            ch = max(ch, s[i]);
        }
        string ans = "";
        for(int i = 0; i < n;i++){
            if(s[i] == ch){
                int del = max(0, numFriends - i);
                string temp = s.substr(i, n - i + 1 - del);
                ans = max(ans, temp);
            }
        }
        return ans;


    }
};