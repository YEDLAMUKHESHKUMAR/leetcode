// Last updated: 4/21/2025, 3:39:00 PM
#define ll long long
class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        ll n = nums.size();
        // :) took some time...but did it...
        ll mini = LLONG_MAX , maxi = LLONG_MIN, sum = 0, ans = 0;
        for(int i = 0; i < n ;i++){
            sum += nums[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }
        cout<<mini<<" "<<maxi;
        for(ll firstElement = lower; firstElement <= upper; firstElement++){
            ll l = firstElement + mini ;
            ll s = firstElement + maxi;
            if( l >= lower && l <= upper && s >= lower && s <= upper ) ans++;
        }
        return ans;

    }
};