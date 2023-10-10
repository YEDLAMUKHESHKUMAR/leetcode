//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool solve(vector<int> &arr,int k,int mid){
        int lastCow = arr[0];
        k--;
        // int min=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i] - lastCow >= mid){
                k--;
                lastCow=arr[i];
            }
            if(k==0) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &arr) {
    
        // Write your code here
        sort(arr.begin(),arr.end());
        int low = 1 , high = arr[n-1] - arr[0] ; 
        int ans = -1;
        while(low<=high){
            int mid = (low + high) / 2 ;
            if(solve(arr,k,mid)==false){
                high = mid - 1 ;
            }
            else{
                ans = mid ;
                low = mid + 1 ;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends