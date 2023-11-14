class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //see notes 
        vector<pair<int,int>> v(26,{-1,-1}); 
        int n = s.size();
        for(int i=0;i<n;i++){
            if(v[s[i]-'a'].first == -1) v[s[i]-'a'].first = i;
            else{
                v[s[i]-'a'].second = i;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(v[i].second != -1){
                unordered_set<char> set ; 
                int firstOccurance = v[i].first ;
                int lastOccurance = v[i].second;
                for(int j = firstOccurance+1; j < lastOccurance ; j++ ){
                    set.insert(s[j]);
                }
                ans+=(int)set.size();

            }
        }
        return ans;
    }
};