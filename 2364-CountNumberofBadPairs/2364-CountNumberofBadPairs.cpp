#define ll long long
class Solution {
public:
    ll countBadPairs(vector<int>& nums) {
        // nums[i] - i != nums[j] - j
        // 4 0 1 0
        ll elements = 0 , ans = 0;
        ll n = nums.size();
        unordered_map<ll,ll> mp;
        for(int i =0; i<n;i++){
            elements++;
            mp[nums[i] - i]++;
            ll remaining = elements - mp[nums[i] - i];
            ans += remaining;
        }
        return ans;
    }
};