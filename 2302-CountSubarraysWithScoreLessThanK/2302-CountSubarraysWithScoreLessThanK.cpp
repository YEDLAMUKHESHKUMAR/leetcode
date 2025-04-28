// Last updated: 4/28/2025, 5:44:02 PM
#define ll long long
class Solution {
public:
    ll bs(ll i, vector<ll> &sum, ll indDelete, ll sumDelete, ll k){
        ll n = sum.size();
        ll low = i, high = n - 1, ans = -1;
        while(low <= high){
            ll mid = (low + high) / 2;
            ll check = (sum[mid] - sumDelete) * ( mid + 1 - indDelete );
            if(check < k) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;

        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        vector<ll> sums;
        ll sum = 0, ans = 0;
        for(int i = 0; i < n ;i++){
            sum += nums[i];
            sums.push_back(sum);
        }

        ll indDelete = 0, sumDelete = 0;
        for(int i = 0; i < n ;i++){
            ll size = bs(i, sums, indDelete, sumDelete, k);
            cout<<size<<endl;
            if(size != -1){
                ans += size - i + 1;
            }


            indDelete++;
            sumDelete += nums[i];
        }
        return ans;

    }
};