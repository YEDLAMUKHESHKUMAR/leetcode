//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        // return -1;
        int ans=-1;
        for(int i=0;i<n;i++){
            bool allZeroes=true;
            for(int j=0;j<n;j++){
                if(m[i][j]!=0){
                    allZeroes=false;
                }
            }
            if(allZeroes==true){
                for(int k=0;k<n;k++){
                    if(i!=k && m[k][i]!=1){
                        return -1;
                    }
                }
                ans=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends