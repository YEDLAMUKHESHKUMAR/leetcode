// Last updated: 4/25/2025, 9:54:22 PM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(int i = 0; i < m ;i++) mp[p[i]]++;

        int j = 0;
        vector<int> ans ;
        for(int i = 0 ; i < n ; i++){
            mp2[s[i]]++;
            while(j <= i && mp2[s[i]] > mp[s[i]]){
                mp2[s[j]]--;
                j++;
            }
            if(i - j + 1 == m) {
                ans.push_back(j);
                mp2[s[j]]--;
                j++;
            }
        }
        return ans;

    }
};