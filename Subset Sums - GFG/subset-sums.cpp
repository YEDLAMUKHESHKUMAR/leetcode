//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

void solve(int i,int sum,vector<int> &arr,vector<int> &ans){
    if(i<0){
        ans.push_back(sum);
        return;
    }
    solve(i-1,sum+arr[i],arr,ans);
    solve(i-1,sum,arr,ans);
    
}
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        solve(n-1,0,arr,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends