#define ll long long
class Solution {
public:
    int numSquares(int n) {
        vector<ll> squares(102, 0);
        for(ll i = 0; i<=100;i++){
            squares[i] = i * i;
        }
        // return 1;
        vector<ll> dp(n + 1, 1e8);
        dp[0] = 0 ;
        for(ll i = 1; i <= n;i++){
            for(ll j = 0; j<=100;j++){
                if(squares[j] <= i){
                    dp[i] = min(dp[i], 1 + dp[i - squares[j]]);
                }
            }
        }
        return dp[n];
    }
};