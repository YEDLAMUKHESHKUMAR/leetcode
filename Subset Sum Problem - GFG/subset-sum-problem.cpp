//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
// bool solve(int i,int target,int n,vector<int> &arr,vector<vector<int>> &dp){
//     if(i==n){
//         if(target==0){                          // memoization + recursion
//             return true;
//         }
//         return false;
//     }
//     if(target==0) return true;
//     if(dp[i][target]!=-1){
//         return dp[i][target];
//     }
//     if(target>=arr[i]){
//         if(solve(i+1,target-arr[i],n,arr,dp)==true) return dp[i][target]=true;
//     } 

//         if(solve(i+1,target,n,arr,dp)==true) return dp[i][target]=true;
//         return dp[i][target]=false;
//     // if(pick==true || notPick==true) return true;
//     // return false;
    
// }
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<bool> prev(sum+1,0),curr(sum+1,0);           // space optimization
        // return solve(0,sum,n,arr,dp);
        prev[0]=true,curr[0]=true;
        prev[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=prev[j];
                bool take=false;
                if(arr[i]<=j){
                    take=prev[j-arr[i]];
                }
                curr[j]=take | notTake;
            }
            prev=curr;
            
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends