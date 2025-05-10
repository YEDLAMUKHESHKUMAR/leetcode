// Last updated: 5/10/2025, 10:50:24 AM
#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size(), m = nums2.size();
        ll sum1 = 0, sum2 = 0;
        ll z1 = 0, z2 = 0;
        for(int i = 0; i < n ;i++){
            sum1 += nums1[i];
            if(nums1[i] == 0) z1++;
        }
        for(int i = 0; i < m; i++){
            sum2 += nums2[i];
            if(nums2[i] == 0) z2++;
        }
        sum1 += z1;
        sum2 += z2;
        if(sum1 == sum2 ) return sum1;
        if(sum1 > sum2){
            if(z2 > 0) return sum1;
            return -1;
        }
        if(z1 > 0 ) return sum2;
        return -1;
    }
};