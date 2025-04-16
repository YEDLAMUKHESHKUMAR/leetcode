// Last updated: 4/16/2025, 11:23:05 AM
#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0 , count  = 0, j = 0 ;
        unordered_map<ll,ll> mp;
        for(int i = 0; i < n ;i++){
            mp[nums[i]]++;
            count += (mp[nums[i]] - 1);
            while(j <= i && count >= k){
                ans += (n - i);
                mp[nums[j]]--;
                count -= (mp[nums[j]]);
                j++;
            }
        }
        return ans;
    }
};