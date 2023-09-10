class Solution {
public:
    int countOrders(int n) {
        long ans=1;
        long mod=(long)1e9+7;       // permutations and combinations 
        for(int i=1;i<=n;i++){
            ans=ans*(i*2-1)*i % mod;
        }
        return (int)ans;
    }
};