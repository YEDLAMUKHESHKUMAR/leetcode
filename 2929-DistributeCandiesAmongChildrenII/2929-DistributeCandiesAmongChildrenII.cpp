// Last updated: 6/1/2025, 8:56:28 PM
#define ll long long

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll ans = 0;
        ll m=n;
        for(ll i = 0; i <= min(m, 1LL * limit) ;i++){
            ll diff = max(0, n - limit);
            if(limit >= n){
                ans += (n + 1);
                n--;
                continue;
            }
            n--;
            if(diff > limit) continue;

            ans += (limit - diff + 1);
        }
        return ans;

    }
};