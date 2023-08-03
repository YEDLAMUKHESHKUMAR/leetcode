class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size()<3){
            return 0;
        }
        unordered_map<int,int> mp;
        int i=0,j=0;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]!=1){
                mp[s[j]]--;
                j++;
            }
            if(i-j+1>=3){
                ans++;
            }
        }
        return ans;
        
    }
};