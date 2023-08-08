class Solution {
public:
    int longestMountain(vector<int>& arr) {
      int left=0,right=0,ans=0;
      int i=1,n=arr.size();
      while(i<n){
          left=0,right=0;
          while(i<n && arr[i-1]<arr[i]){
              left++;
              i++;
          }
          while(i<n && arr[i-1]>arr[i]){
              right++;
              i++;
          }
          if(left>0 && right>0){
              ans=max(ans,left+right+1);
          }
          while(i<n && arr[i-1]==arr[i]){
              i++;
          }
      } 
      return ans;
    }
};