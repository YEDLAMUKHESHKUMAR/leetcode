// Last updated: 4/3/2025, 5:30:09 PM
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // see my solution for the first version of this question... :)
        ll n = nums.size();
        ll maxIJdiff = 0, maxOnLeft = 0, maxAns = 0;
        for(int i = 0; i < n ; i++){
            maxAns = max(maxAns, 1LL * nums[i] * maxIJdiff  );
            maxIJdiff = max(maxIJdiff, maxOnLeft - nums[i] );
            maxOnLeft = max(maxOnLeft, 1LL * nums[i]);
        }
        return maxAns;
    }
};