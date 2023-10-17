class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> sum(n);     // :) :) :) 
        stack<int> st;
        int j,ans = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                j=-1;
            }
            else{
                j=st.top();
            }
            sum[i]=(i-j)*arr[i] % mod;
            if(j>=0){
                sum[i]+=sum[j];
            }
            st.push(i);
        }
        for(int i=0;i<sum.size();i++){
            ans = (ans + sum[i])%mod;
        }
        return ans;
    }
};