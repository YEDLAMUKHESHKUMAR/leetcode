class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> oddPositions;
        vector<long long> dp(n + 1, 0);
        for(int i = 0; i < n; i++){
            if( arr[i] % 2 == 1 ){
                oddPositions.push_back(i);
            }
        }
        int m = oddPositions.size() ; 
        if(m == 0) return 0;
        int lastOddPosition = oddPositions[m-1];
        dp[lastOddPosition] = n - lastOddPosition ;

        for(int i = m - 2; i >= 0 ;i--){
            int ind = oddPositions[i];
            dp[ind] = dp[ind] + (oddPositions[i + 1] -  oddPositions[i] ) % mod;
            if(i + 2 < m){
                dp[ind]  = dp[ind] + dp[oddPositions[i + 2]] % mod;
            }
        }
       
        long long ans = 0;
        for(int i = n - 1; i>= 0;i--){
            if(arr[i] % 2 == 0){
                ans =  ans + dp[i + 1]  % mod;
                dp[i] = dp[i + 1];
            }
            else ans =  ans + dp[i] % mod;
        }
        return ans % mod;

    }
};