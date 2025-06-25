// Last updated: 6/25/2025, 1:15:53 PM
#define ll long long
class Solution {
public:
    ll solve(ll mid, vector<int>& nums1, vector<int>& nums2){
        ll n = nums1.size(), m = nums2.size();
        ll ans = 0;
        for(int i = 0; i < n ;i++){
            ll denom = nums1[i];
            if(denom == 0){
                if(mid >= 0) ans += m;
                continue;
            }
            ll x = mid / denom;
            if(mid < 0){
                if(mid % denom != 0) {
                    if(denom >=0) x--;
                    else x++;
                }
            }
            if(denom > 0){
                // find index in nums2 where <=x
                auto it = upper_bound(nums2.begin(), nums2.end(), x);
                ans += (it - nums2.begin());
            }
            else{ 
                // >=x
                auto it = lower_bound(nums2.begin(), nums2.end() , x);
                ans += (nums2.end() - it);
            }          
        }
        cout<<mid<<" "<<ans<<endl;
        return ans;


    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        // return 1;
        // 0 case
        
        ll n = nums1.size(), m = nums2.size();
        // ll low = min({ 1LL*  nums1[0] * nums2[0] ,1LL*  nums1[0] * nums2[m - 1],1LL*  nums1[n-1] * nums2[0] ,1LL*  nums1[n - 1] * nums2[m - 1] });
        // ll high = max({ 1LL* nums1[0] * nums2[0] ,1LL*  nums1[0] * nums2[m - 1],1LL*  nums1[n-1] * nums2[0] , 1LL* nums1[n - 1] * nums2[m - 1] });
        ll low = -1e10, high = 1e10; 
        ll ans = -1;
        while(low <= high){
            ll mid = (low + high) / 2;
            ll prods = solve(mid, nums1, nums2);
            // cout<<mid<<" ";
            if(prods < k ){ // check this oce
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};