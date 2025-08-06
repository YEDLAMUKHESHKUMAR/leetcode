// Last updated: 8/6/2025, 10:55:23 AM

#define ll long long
class Solution {
public:
    ll solve(vector<int>& nums, ll target){
        ll n = nums.size();
        unordered_map<ll,ll> mp;
        ll sum = 0, ans = INT_MAX;
        for(ll i = 0 ; i < n ;i++){
            sum += nums[i];
            if(sum == target) ans = min(ans, i + 1);
            if(mp.find(sum - target) != mp.end() ){
                ans = min(ans, i - mp[sum - target]);
            }
            mp[sum] = i;
        }
        return ans;
    }
    int minSizeSubarray(vector<int>& nums, int target) {
        ll m = nums.size();
        ll sum = 0;
        for(int i = 0; i < m ;i++){
            nums.push_back(nums[i]);
            sum += nums[i];
        }
        // if(sum == target) return m;
        // cout<<sum<<endl;
        ll n = nums.size();
        ll rem = target % sum;
        ll k = target / sum;
        ll ans = k * m;
        if(rem == 0) return ans;
        ll val = solve(nums, rem);
        if(val == INT_MAX) return -1;
        return val + ans;

    }
};