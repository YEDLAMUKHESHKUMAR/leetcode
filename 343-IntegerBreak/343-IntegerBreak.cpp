// Last updated: 5/6/2025, 11:37:08 AM
#define ll long long
class Solution {
public:
    ll solve(ll element, vector<ll> &dp ){
        ll ans = 1;
        for(ll i = 1 ; i <= element/ 2; i++ ){
            ll sec = element - i;
            ans = max( ans, max(i, dp[i]) * max(sec, dp[sec]) );
        }
        return ans;
    }
    int integerBreak(int n) {
        // vector<int> 
        vector<ll> dp(60, 1);
        dp[1] = 0;
        dp[2] = 1;
        for(ll i = 3; i <= n ; i++){
            ll getMaxAns = solve(i, dp);
            dp[i] = getMaxAns;
        }
        return dp[n];
    }
};