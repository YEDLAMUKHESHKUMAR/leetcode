class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int i=0,j=0,zero_count=0;
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0){              // :)
                zero_count++;
            }
            
            while(zero_count>k){
                if(arr[j]==0){
                        zero_count--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};