// Last updated: 6/29/2025, 11:55:09 AM
#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    ll expo(ll  n){
        ll ans = 1;
        ll a = 2;
        while(n > 0){
            if(n % 2 ){
                ans = ans * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll total = expo(n) - 1;
        cout<<total<<endl;
        ll remove = 0;
        for(int i = 0; i < n ;i++){
            auto it = upper_bound(nums.begin(),nums.end(), target - nums[i]);
            if(it != nums.end()){
                ll ind = it - nums.begin(); 
                // cout<<ind;
                ll len = 0;
                if(i >= ind){
                    len = i - ind ;
                    // cout<<i<<" : "<<ind<<" "<<len<<endl;
                    remove = (remove + ( expo(len) )) % mod;
                }
            }
        }
        return ( total - remove + mod ) % mod;
    }
    
};