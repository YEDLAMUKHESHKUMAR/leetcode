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
        for(auto i: wordDict) mp[i]++;   // :)
        // my dp[i] will tell me, whether i can reach to the end , if i start the process from here, 
        // eg : for the first test case....consider the wordDict also contains : "l", "e", "le"...
        // now , in s = "leetcode", i can reach to the index 2, either by taking "l" , "e"  or "le"
        // in any way, i wouldn't be able to make it to the end, if i reach the index 2, so that's it....
        vector<int> dp(n, -1);
        return solve(0, s, mp, dp);
    }
};