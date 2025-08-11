// Last updated: 8/11/2025, 11:05:53 PM
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1) return n;   // DO LC - 5 first ( longest palindromic substring)
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<pair<int,int>> pos;
        for(int i = 0; i < n ;i++) dp[i][i] = 1;
        for(int i = 0; i < n ; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = 1;
                if(k == 2) {
                    pos.push_back({i, i + 1});
                }
            }
        }
        
        for(int len = 3 ; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = 1;
                    if(len >= k) pos.push_back({i, j});
                }
            }
        }
        if(pos.empty()) return 0;
        sort(pos.begin(), pos.end());
    
        int non_overlapping = 0;
        int end = pos[0].second;
        bool last = false;
        for(int i = 1; i < pos.size() ; i++){
            if(pos[i].first <= end){
                end = min(end, pos[i].second);
            }
            else{
                end = pos[i].second;
                non_overlapping++;
            }
        }
        
        non_overlapping++;
        return non_overlapping;
    }
};