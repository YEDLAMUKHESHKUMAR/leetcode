class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
        }
        int len = 0;
        for(auto i:mp){
            if(i.second % 2 == 0) len+=2;
            else len+=1;
        }
        return len;
    }
};