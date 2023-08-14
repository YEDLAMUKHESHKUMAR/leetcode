//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
    public:
    int lastSeenElement(int arr[], int n)
    {
        // Complete the function
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int ans=INT_MAX;
        for(auto i:mp){
            if(i.second<ans){
                ans=i.second;
            }
        }
        return arr[ans];
    }
 
};

//{ Driver Code Starts.

 
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    int n;
    cin >> n;
    int a[n];
    
    for(int i=0;i<n;i++)
    cin >> a[i];
    Solution ob;
    cout << ob.lastSeenElement(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends