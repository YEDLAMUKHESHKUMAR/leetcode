class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // notes
        unordered_map<int,int> mp ;
        int n = arr.size();       // optimized code :) :(
        for(int i=0;i<n;i++){
            mp[min(n,arr[i])]++;  // as i said .. we dont need numbers > n 
        }
        int ans = 1; // similar to 1st approach
        for(int i=2;i<=n;i++){
            ans = ans+mp[i];
            if(i<ans){
                ans = i ;
            }
        }
        return ans;
        
        // sort(arr.begin(),arr.end());       // we can optimize it :)
        // int x = 1 ;
        // arr[0]=1;
        // for(int i=1;i<arr.size();i++){
        //     if(arr[i]-arr[i-1] > 1){
        //         x++;
        //         arr[i]=x;
        //     }
        //     else{
        //         x=arr[i];
        //     }
        // }
        // return x;

    }
};