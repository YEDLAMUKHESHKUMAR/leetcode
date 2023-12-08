class Solution {
public:
    bool checkInclusion(string p, string s) {
       unordered_map<char,int> mp;
        unordered_map<char,int> mp2;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;                      // :) :) :) 
        }
        int i=0;
        int j=0;
        while(j<s.size()){
            mp2[s[j]]++;
            if(mp.find(s[j])==mp.end()){
                while(mp2[s[j]] > 0){
                    mp2[s[i]]--;
                    i++;
                }
            }
            if(mp2[s[j]]> mp[s[j]]){
                while(mp2[s[j]] > mp[s[j]]){
                     mp2[s[i]]--;
                    i++;
                }
            }
            if(j-i+1 == p.size()){
                return true;
            }
            j++;

        }
        return false;
    }
};