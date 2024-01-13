class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        int n = s.size(); 
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        } 
        int minReplacements = 0;
        for(int i=0;i<n;i++){
            char currChar = t[i];
            if(mp[currChar] > 0 ){
                mp[currChar]--;
            }
            else{
                minReplacements++;
            }
        }
        return minReplacements;
    }
};