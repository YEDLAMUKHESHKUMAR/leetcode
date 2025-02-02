class Solution {
public:
    string findValidPair(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i<n;i++){
            mp[s[i]]++;
        }
        string ans = "";
        for(int i = 0; i<n-1;i++){
            if(s[i] != s[i+1]){
                int num1 = s[i] - '0';
                int num2 = s[i+1] - '0';
                if(mp[s[i]] == num1 &&  mp[s[i+1]] == num2 ){
                    ans += s[i];
                    ans += s[i+1];
                    return ans;
                }
            }
        }
        return ans;
    }
};