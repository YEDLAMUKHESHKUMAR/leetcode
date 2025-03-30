// Last updated: 3/30/2025, 1:04:46 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> mp(26, 0);
        vector<int> ans;
        for(int i = 0; i < n ;i++){
            mp[s[i] - 'a'] = i;
        }
        int maxLen = 0, prev = 0;
        
        for(int i = 0; i < n ;i++){
            maxLen = max(maxLen, mp[s[i] - 'a']);
            if(maxLen == i){
                ans.push_back(maxLen + 1 - prev);
                prev = maxLen + 1;
                maxLen = 0;
            }
        }
        return ans;

    }
};