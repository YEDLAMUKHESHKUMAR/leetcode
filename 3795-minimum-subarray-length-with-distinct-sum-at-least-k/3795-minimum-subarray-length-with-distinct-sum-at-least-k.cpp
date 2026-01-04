#define ll long long
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        ll n = nums.size();
        ll sum = 0;
        unordered_map<ll,ll> mp;
        ll j = 0;
        ll ans = INT_MAX, totalSum = 0;
        for(ll i = 0; i < n ;i++){
            totalSum += nums[i];
            mp[nums[i]]++;
            
            if(mp[nums[i]] == 1){
                sum += nums[i];
            }
            while(j <= i && sum >= k){
                ans = min(ans, i - j + 1);
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    sum -= nums[j];
                    mp.erase(nums[j]);
                }
                j++;

            }
        }
        // if(totalSum < k) return -1;
        return ans==INT_MAX ? -1 : ans;
    }
};