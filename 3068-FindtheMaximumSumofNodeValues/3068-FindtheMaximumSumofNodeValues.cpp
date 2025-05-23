// Last updated: 5/23/2025, 11:15:06 AM
#define ll long long

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0;
        ll n = nums.size();
        ll taken = 0, minPutDiff = INT_MAX , minSacrificeDiff = INT_MAX;
        ll K = k;
        for( int i = 0; i < n ;i++ ){
            ll x = nums[i] ^ K;
            cout<<x<<" ";
            if(nums[i] > x){
                if( abs(x - nums[i]) < minPutDiff){
                    minPutDiff = abs(x - nums[i]);
                }
                ans += nums[i];
                // no < ??
            }
            else{
                taken++;
                ans += x;
                minSacrificeDiff = min(minSacrificeDiff, abs(x - nums[i]));
            }
        }
        if(taken % 2 == 0) return ans;
        ll t1 = ans - minSacrificeDiff;
        if(minPutDiff == INT_MAX){
            return t1;
        }
        ll t2 = ans - minPutDiff;
        return max(t1, t2);
    }
};