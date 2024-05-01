class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        int n = word.size();
        bool check = false;
        for(int i = 0 ;i<n;i++){
            if(word[i] == ch && check == false){
                check = true;
                ans = word[i] + ans;
            }
            else if(check == true){
                ans+=word[i];
            }
            else ans = word[i] + ans;
        }
        if(check == false) return word;
        return ans;
    }
};