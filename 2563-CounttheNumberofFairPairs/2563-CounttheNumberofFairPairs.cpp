// Last updated: 4/19/2025, 2:46:17 PM
#define ll long long
class Solution {
public:
    ll bs(ll tar, vector<int> &nums,ll s,  ll n){
        ll low = s, high = n - 1, ans = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(nums[mid] >= tar){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;

    }
    ll bs2(ll tar, vector<int> &nums ,ll s,  ll n){
        ll low = s, high = n - 1, ans = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(nums[mid] <= tar ){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // aced in one, go....  :) ...
        // do this again....
        // 0 + x <= 6
        // 0 + x >= 3
        sort(nums.begin(), nums.end());
        ll n = nums.size();
        ll ans = 0;
        for(int i = 0; i < n ;i++){
            ll l =  lower - nums[i];
            ll r = upper - nums[i];
            ll ind1 = bs(l, nums,i + 1,  n);
            ll ind2 = bs2(r, nums, i + 1,  n);
            cout<<"i : "<<i<<"ind1 : "<<ind1<<" "<<ind2<<endl;
            if(ind1 == -1 || ind2 == -1) continue;
            if(ind2 >= ind1 && ind2 > i) ans += (ind2 - ind1 + 1);
            
        }
        return ans;
    }
};