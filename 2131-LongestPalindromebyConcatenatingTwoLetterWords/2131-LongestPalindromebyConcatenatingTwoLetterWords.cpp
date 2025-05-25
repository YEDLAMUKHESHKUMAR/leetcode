// Last updated: 5/25/2025, 9:03:23 AM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        unordered_map<string, int> freq;
        int ans = 0;
        char f, s;
        for(int i = 0 ; i< n;i++){
            f = words[i][0]; s = words[i][1];
            string search = "" ;
            search += s;
            search += f;
            // cout<<search<<" ";
            if(f == s) {
                freq[words[i]]++;
            }
            else if(( mp[search] > 0 ) ){
                ans += 4;
                mp[search]--;
            }
            else mp[words[i]]++;
        }
        bool odd = false;
        for(auto i  : freq){
            if(i.second % 2 == 1){
                odd = true;
                ans += ((i.second - 1) * 2) ; 
            }
            else ans += (i.second * 2);
        }
        return ans + (odd ? 2 : 0);
    }
};