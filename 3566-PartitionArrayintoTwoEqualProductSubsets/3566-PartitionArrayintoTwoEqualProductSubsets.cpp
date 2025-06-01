// Last updated: 6/1/2025, 11:22:50 AM
#define ll long double
class Solution {
public:
    // bool solve()
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        // return solve(0, nums, target);
        int n = nums.size();
        ll prod = 1;
        for(int i = 0;  i < n ;i++){
            prod *= nums[i];
        }
        for(int i = 0; i < (1 << n) ; i++){
            ll p = 1, np = 1;
            for(int pos = 0; pos < 32 ;pos++){
                if( (i >> pos) & 1 ){
                    p *= nums[pos];
                }
                else if(pos < n ){
                    np *= nums[pos];
                }
            }
            if(p == target && np == target){
                // cout<<i;
                return true;
            }
        }

        return false;
    }
};