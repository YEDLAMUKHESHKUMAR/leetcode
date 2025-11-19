class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        long long mod = 1e9 + 7;
        long long ans = 0, c = 0;
        for(int i = 0; i < n ;i++){
            if(s[i] == '1'){
                c++;
            }
            else{
                long long curr = ((c )* (c + 1) ) / 2 ; // c * (c + 1 / 2)
                ans  =  (ans +  curr) % mod;
                c = 0;
            }

        }
        long long curr = ((c )* (c + 1) ) / 2 ; // c * (c + 1 / 2)
        ans  =  (ans +  curr) % mod;        
        return (int)ans ;
    }
};