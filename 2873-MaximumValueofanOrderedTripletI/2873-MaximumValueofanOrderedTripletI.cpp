// Last updated: 4/2/2025, 5:14:40 PM
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n = nums.size(), maxi = 0, ans = 0;
        vector<ll> leftMax(n + 1, 0);
        for(int i = 0; i < n;i++){
            leftMax[i] = maxi;
            maxi = max(maxi,1LL * nums[i]);
        }
        maxi = nums[n-1];
        for(int i = n - 2 ; i>=0 ;i--){
            ans = max(ans, ( leftMax[i] - nums[i] ) * maxi  );
            maxi = max(maxi, 1LL * nums[i]);
        }
        return ans;
    }
};