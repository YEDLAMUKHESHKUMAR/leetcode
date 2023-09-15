//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isequal(int i,int arr[],int target,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(i==0){
            return (arr[0]==target);
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool notTake= isequal(i-1,arr,target,dp);
        bool take=false;
        if(arr[i]<=target){
            take=isequal(i-1,arr,target-arr[i],dp);
        }
        return dp[i][target]=take|notTake;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return isequal(n-1,arr,sum,dp);
        // for(int i=0;i<n;i++){
        //     dp[i][0]=true;
        // }
        // dp[0][arr[0]]=true;
        // for(int i=1;i<n;i++){
        //     for(int target=0;target<=sum;target++){
        //         bool notTake=dp[i-1][target];
        //         bool take=false;
        //         if(arr[i]<=target){
        //             take=dp[i-1][target-arr[i]];
        //         }
        //         dp[i][target]= take | notTake;
        //     }
        // }
        // return dp[n-1][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends