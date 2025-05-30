// Last updated: 5/30/2025, 11:38:56 PM
#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        // return 1;
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>> (m));
        ll mod = 1e9 + 7;
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < m ;j++){
                if(i == 0 && j == 0) continue;
                ll maxi = -1e16;
                ll mini = 1e16;
                ll val = grid[i][j];
                if(i > 0) {
                    ll t = dp[i-1][j].first;
                    ll l = dp[i-1][j].second;

                    maxi = max(maxi, max( val * t ,val * l  ) );
                    mini = min(mini, min(val * t, val * l));
                    // maxi = max(maxi,  (max((val % mod) * dp[i-1][j].first,(val % mod) * dp[i-1][j].second) % mod) % mod; 
                    // mini =  (min((val % mod) * dp[i-1][j].first,(val % mod) *  dp[i-1][j].second) % mod) % mod; 
                    
                }
                if(j > 0){
                    ll t = dp[i][j-1].first;
                    ll l = dp[i][j-1].second;

                    maxi = max(maxi, max( val * t ,val * l  ) );
                    mini = min(mini, min(val * t, val * l));

                    // maxi = (val % mod) * (max(dp[i-1][j].first, dp[i-1][j].second) % mod) % mod; 
                    // mini = (val % mod) * (min(dp[i-1][j].first, dp[i-1][j].second) % mod) % mod; 
                }
                dp[i][j] = {maxi, mini};
            }
        }
        ll f = dp[n-1][m-1].first , s = dp[n-1][m-1].second;
        if(f < 0 && s < 0) return -1;
        return max(f,s) % mod;
        // return max(dp[n-1][m-1].first , dp[n-1][m-1].second);
    }
};