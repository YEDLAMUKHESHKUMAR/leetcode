#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        ll ans = 0;
        ll mini = INT_MAX;
        ll extra = nums2[n];
        for(int i = 0; i < n ; i++){
            ll left = min(nums1[i], nums2[i]);
            ll right = max(nums2[i], nums1[i]);
            if(extra >= left &&  extra <= right ){
                mini = 0;
            }
            else{
                mini = min(mini, min(abs(extra - left), abs(extra - right) ));
            }
            ans += abs(left - right);
        }
        return ans + mini + 1;
    }
};