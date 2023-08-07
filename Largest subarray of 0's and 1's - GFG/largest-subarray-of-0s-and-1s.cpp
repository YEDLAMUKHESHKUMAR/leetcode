//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        // Your code here
        unordered_map<int,int> mp;           // good approach
        for(int i=0;i<n;i++){
            if(arr[i]==0) arr[i]=-1;
        }
        int check=0;
        mp[0]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            check+=arr[i];
            if(mp.find(check)!=mp.end()){
                ans=max(ans,i+1-mp[check]);
            }
            else{
                mp[check]=i+1;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends