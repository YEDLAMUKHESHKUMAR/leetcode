#define ll long long
class Solution {
public:
    ll solve(ll tar, vector<int> &nums, ll k){
        ll n = nums.size(), child = 0;
        for(int i = 0; i< n;i++){
            child += (nums[i] / tar);
        }
        return child >=k ? true : false;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
        ll sum = 0, mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i< n ;i++){
            sum += nums[i];
            maxi = max(maxi, 1LL * nums[i]);
        }
        if(sum < k ) return 0;
        ll low = 1, high = maxi, ans = 0;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(solve(mid, nums, k) == true){
                ans = mid;
                low = mid + 1 ;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};