class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;  
        }
        unordered_map<int,int> mp;
        int c=0,maxx=INT_MIN;
        int j=0;
        for(int i=0;i<s.size();i++){
                while(mp[s[i]]!=0){
                    mp[s[j]]--;
                    c--;
                    j++;
                    
                }
            c++;
            mp[s[i]]++;
            maxx=max(maxx,c);
            }

     
        return maxx;
    }
};