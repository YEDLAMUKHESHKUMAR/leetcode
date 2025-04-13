// Last updated: 4/13/2025, 9:42:59 AM
#define ll long long 
class Solution {
public:
    int mod = 1e9 + 7;
    ll expo(ll a, ll b){
        ll ans = 1;
        while(b){
            if(b % 2 == 1){
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return ans % mod;
    }
    int countGoodNumbers(long long n) {
        ll fives = 0, fours = 0;
        fives += (n / 2);
        fours += (n / 2);
        fives += (n % 2 != 0 ? 1 : 0);
        ll pow1 = expo(5, fives) % mod;
        ll pow2 = expo(4, fours) % mod;

        return (pow1 * pow2 ) % mod;

    }
};