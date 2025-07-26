// Last updated: 7/26/2025, 11:54:35 AM
#define ll long long
class Solution {
public:
    ll mod = 1000000007;
    int solve(ll i, ll sum,  ll k, vector<int>& nums, vector<vector<ll>>& dp){
        if(sum >= k) return 0;
        if(i >= nums.size()) {
            return sum < k ;
        }
        if(dp[i][sum] != -1 ) return dp[i][sum];
        ll take = solve(i + 1, sum + nums[i], k, nums, dp) % mod;
        ll leave = solve(i + 1, sum, k, nums, dp) % mod;
        return dp[i][sum] = (take + leave) % mod;
    }
    int countPartitions(vector<int>& nums, int k) {
        ll sum = 0;
        ll totalSub = 1;
        for(int i = 0; i < nums.size() ;i++) {
            sum += nums[i];
            totalSub = (2LL *  totalSub ) % mod;
        }
        if(sum < (2LL * k)) return 0;

        vector<vector<ll>> dp(nums.size() + 1, vector<ll> (k + 1, -1));
        ll del = solve(0, 0, k, nums, dp) % mod;
        del = 2LL * del % mod;
        return ( totalSub - del + mod )% mod;

    }
};