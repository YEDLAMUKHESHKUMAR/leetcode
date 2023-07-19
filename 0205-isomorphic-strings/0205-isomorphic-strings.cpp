class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> mp;
        unordered_map<char,int> check;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]!=check[t[i]]) return false;
            mp[s[i]]=i+1;
            check[t[i]]=i+1;
        }
        return true;
    }
};