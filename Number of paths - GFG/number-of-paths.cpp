//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // Code Here
    vector<vector<int>> dp(m,vector<int> (n,-1));
    dp[0][0]=1; 
    
    for(int i=0;i<m;i++){
        int left=0,up=0;
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        
    }
    return dp[m-1][n-1];
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends