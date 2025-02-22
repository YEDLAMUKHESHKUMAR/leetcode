class Solution {
public: 
    // bool ans = false;
    bool solve(int i , string &s, unordered_map<string,int> &mp, vector<int> &dp ){
        if(i >= s.size()) return true;
        if(dp[i] != -1) return dp[i];
        string temp = "";
        for(int ind = i ;ind < s.size(); ind++){
            temp += s[ind];
            if(mp.find(temp) != mp.end()){
                cout<<temp<<endl;
                if(solve(ind + 1, s, mp, dp)) return dp[ind] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string,int> mp;
        for(auto i: wordDict) mp[i]++;   // :)  notes
        
        vector<int> dp(n, -1);
        return solve(0, s, mp, dp);
    }
};