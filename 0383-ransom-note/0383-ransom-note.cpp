class Solution {
public:
    bool canConstruct(string r, string m) {
        if(r.size()>m.size()) return false;
        unordered_map<char,int> mp;
        for(int i=0;i<m.size();i++){
            mp[m[i]]++;
        }
        for(int i=0;i<r.size();i++){
            if(mp[r[i]]==0) return false;
            mp[r[i]]--;
        }
        return true;
    }
};