class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0, j = 0 ;
        map<char, int> mp;
        for(int i = 0; i < n ;i++){
            mp[s[i]]++;
            while(j <= i && mp.size() == 3){
                ans += (n - i);
                mp[s[j]]--;
                if(mp[s[j]] == 0) mp.erase(s[j]);
                j++; 
            }
        }
        return ans;
    }
};