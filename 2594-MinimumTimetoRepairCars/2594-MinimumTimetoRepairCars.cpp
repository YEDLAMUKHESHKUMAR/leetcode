#define ll long long
class Solution {
public:
    ll solve(ll tar, vector<int> &nums, ll cars){
        ll n = nums.size();
        ll carsIcanMake = 0;
        for(int i = 0; i < n;i++){
            ll val = tar / nums[i];
            ll c = sqrt(val);
            carsIcanMake += c;
        }
        return carsIcanMake >= cars ? true : false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        // x * x = 8
        int n = ranks.size();
        int maxi = *max_element(ranks.begin(), ranks.end());
        ll low = 1, high = 1LL * maxi * cars * cars, ans = 0;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(solve(mid, ranks, 1LL * cars)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
        
    }
};