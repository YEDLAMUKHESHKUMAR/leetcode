// Last updated: 6/24/2025, 11:44:14 PM
class Solution {
public:
    void solve(int ind, string& s, int sz, int m, unordered_map<string,int>& mp, vector<int>& ans){
        int n = s.size();
        unordered_map<string, int> freq;
        int i = ind, j = ind, c = 0;
        while(i < n ){
            string sub = s.substr(i, sz);
            cout<<sub<<" ";
            c++;
            freq[sub]++;
            while(j <= i && freq[sub] > mp[sub]){
                freq[s.substr(j, sz)]--;
                c--;
                j += sz;
            }
            if(c == m) ans.push_back(j);
            i+=sz;
        }

    }
    vector<int> findSubstring(string s, vector<string>& words) {
        // int n = s.size();
        int m = words.size();
        unordered_map<string, int> mp;
        for(auto word : words){
            mp[word]++;
        }
        int sz = words[0].size();
        vector<int> ans;
        for(int i = 0; i < sz; i++){
            solve(i, s, sz, m, mp, ans);
        }
        return ans;
    }
};