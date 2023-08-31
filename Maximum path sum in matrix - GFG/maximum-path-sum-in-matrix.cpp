//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> arr)
    
    {
        // vector<vector<int>> dp(n,vector<int> (n,0));   
        // for(int i=0;i<n;i++){
        //     dp[0][i]=arr[0][i];
        // }
        // for(int i=1;i<n;i++){
        //     int up;
        //     int up_right;
        //     int up_left;
        //     for(int j=0;j<n;j++){
        //         up=arr[i][j]+dp[i-1][j];
        //         up_left=arr[i][j];
        //         if(j>=0) up_left+=dp[i-1][j-1];            // why the hell we should write j>=0 instead j>0 ...we cannot access index if j=0
        //         else up_left+=-1e9;
        //         up_right=arr[i][j];
        //         if(j+1<n) up_right+=dp[i-1][j+1];
        //         else up_right+=-1e9;
        //         dp[i][j]=max(up,max(up_left,up_right));
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,dp[n-1][i]);
        // }
        // return ans;
        // code here
        vector<vector<int>> dp(n,vector<int> (n,-1));    
        for(int i=0;i<n;i++){
            int up=0;
            int up_right=0;
            int up_left=0;
            for(int j=0;j<n;j++){                        
                if(i==0 && j==0) {
                    dp[i][j]=arr[i][j];
                    continue;
                }
                if(i>0) up=dp[i-1][j];
                if(i>0 && j>=0) up_left=dp[i-1][j-1];     // :) ...in this if i put j>0 its not working
                if(i>0 && j+1<n) up_right=dp[i-1][j+1];    // if i put j+1<n ...it is not working
                dp[i][j]=arr[i][j]+max(up,max(up_left,up_right));
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[n-1][i]);
        }
        return ans;
        //610311225
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends