// Last updated: 8/11/2025, 9:57:14 AM
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> powers;
        int mod = 1000000007;
        for(int i = 0; i < 32 ; i++){
            if( ( n >> i  ) & 1 ){
                powers.push_back( ( 1 << i ) );
            }
        }
        int m = powers.size();
        
        int qs = q.size();
        vector<int> res;
        for(int i = 0; i < qs; i++){
            int left = q[i][0];
            int right = q[i][1];
            int prod = 1;
            for(int j = left ; j <= right ;j++){
                prod = ( (1LL * prod % mod) *  ( powers[j] % mod ) ) % mod;
            }
            res.push_back(prod);
        }
        return res;
    }
};