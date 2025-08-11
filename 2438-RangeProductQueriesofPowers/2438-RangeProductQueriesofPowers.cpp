// Last updated: 8/11/2025, 10:07:34 AM
class Solution {
public:
    int mod = 1000000007;

    int expo(int a, int b){
        if(a == 1) return 1;
        int ans = 1;
        while(b){
            if(b & 1){
                ans = 1LL * ans * a % mod;
            }
            a = 1LL * a * a % mod;
            b = ( b >> 1);
        }
        return ans;
    }
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> powers;
        for(int i = 0; i < 32 ; i++){
            if( ( n >> i  ) & 1 ){
                powers.push_back( ( 1 << i ) );
            }
        }
        int m = powers.size();
        int prod = 1;
        for(int i = 0; i < m ;i++){
            prod = ( (1LL * prod % mod) *  ( powers[i] % mod ) ) % mod;
            powers[i] = prod;
        }
        int qs = q.size();
        vector<int> res;
        for(int i = 0; i < qs; i++){
            int left = q[i][0];
            int right = q[i][1];
            int ans = 1LL * powers[right] * expo( left - 1 >= 0 ? powers[left - 1] : 1, mod - 2 ) % mod;
            res.push_back(ans);
        }
        return res;
    }
};