class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();
        unordered_map<string, int> seen;
        string curr = "";
        vector<string> ans;
        for(int i = 0 ; i < n ;i++){
            curr += s[i];
            if(seen.find(curr) != seen.end()) continue;
            seen[curr]++;
            ans.push_back(curr);
            curr = "";
        }
        return ans;
    }
};