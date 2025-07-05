// Last updated: 7/5/2025, 10:55:18 PM
#define ll long long
class Solution {
public:
    ll solve(ll i, ll j, ll n, ll m, vector<vector<int>>& grid, vector<vector<ll>>& dp ){
        if( i < 0 || i >= n || j < 0 ||  j >= m ) return 1e16;
        if(i == n -1 && j == m - 1 ) return (n * m);
        if(dp[i][j] != -1) return dp[i][j];
        ll wait = grid[i][j];
        ll cost = (i + 1) * (j + 1);
        ll right = wait + cost + solve(i , j + 1, n, m, grid, dp);
        ll down = wait + cost + solve(i + 1, j , n, m, grid, dp);

        return dp[i][j] = min(right, down);
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<ll>> dp(m + 1, vector<ll> (n + 1, -1));
        return solve(0, 0, m, n, waitCost, dp) - waitCost[0][0];
    }
};