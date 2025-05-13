// Last updated: 5/13/2025, 5:28:53 PM
#define ll long long
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // notes :)
        ll mod = 1e9 + 7;
        ll n = s.size();
        vector<ll> mp(26, 0);
        for(ll i = 0; i < n ;i++){
            mp[s[i] - 'a']++;
        }
        for(ll i = 0; i < t ;i++){
            vector<ll> temp(26, 0);
            for(ll i = 0; i < 26 ;i++){
                ll newKey = ( i + 1 ) % 26;

                temp[newKey] = (temp[newKey] + mp[i]) % mod;
                if(i == 25) temp[1] = (temp[1] + mp[i]) % mod;

            }
            mp = temp;
        }
        ll ans = 0;
        for(ll i = 0; i < 26; i++){
            ans = ( ans + mp[i] ) % mod;
        }
        return ans % mod;
    }
};