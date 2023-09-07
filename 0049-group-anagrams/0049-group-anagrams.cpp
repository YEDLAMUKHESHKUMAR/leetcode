class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string, vector<string>> mp;
        int n=str.size();
        for(int i=0;i<n;i++){
            string curr_string=str[i];
            sort(curr_string.begin(),curr_string.end());
            mp[curr_string].push_back(str[i]);
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};