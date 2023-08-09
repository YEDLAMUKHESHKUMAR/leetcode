//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int MissingNumber(int a[], int b[], int k, int n, int m)
    {
        // Complete the function
        unordered_map<int,int> mp;    // :)
        for(int i=0;i<m;i++){
            mp[b[i]]++;
        }
        for(int i=0;i<n;i++){
            if(!(mp[a[i]]>0)){
                k--;
            }
            if(k==0){
                return a[i];
            }
            
        }
        return -1;
        // int l=0,r=n-1, mid;
        // unordered_map<int,int> mp;
        // for(int i=0;i<m;i++){
        //     l=0,r=n-1;
        //     while(l<=r){
        //         mid=(l+r)/2;
        //         if(a[mid]==b[i]){
        //             mp[b[i]]++;
        //             break;
        //         }
        //         else if(a[mid]>b[i]){
        //             r=mid-1;
        //         }
        //         else{
        //             l=mid+1;
        //         }
        //     }
            
        // }
        // for(int i=0;i<n;i++){
        //     if(mp[a[i]]==0){
        //         k--;
        //     }
        //     if(k==0){
        //         return a[i];
        //     }
        // }
        // return -1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.MissingNumber(a, b, k, n, m)<<endl;

    }
    return 0;
}

// } Driver Code Ends