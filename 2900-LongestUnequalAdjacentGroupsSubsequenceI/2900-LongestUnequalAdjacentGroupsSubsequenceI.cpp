// Last updated: 5/15/2025, 2:20:27 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int prev = groups[0];
        vector<string> ans;
        ans.push_back(words[0]);

        for(int i = 1 ; i < n ;i++){
            if(prev == groups[i]) continue;
            ans.push_back(words[i]);
            prev = groups[i];
        }
        return ans;
    }
};