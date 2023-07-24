//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int n) {
        // code here
        int steps=0;
        int zero_count=0;
        int negative_count=0;    // :)
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zero_count++;
                steps++;
            }
            else if(arr[i]<0){
                negative_count++;
                steps=steps+(-1-arr[i]);
            }
            else{
                steps+=(arr[i]-1);
            }
            
            
        }
        if(negative_count%2!=0){
            if(zero_count>0){
                return steps;
            }
            steps+=2;
        }
        return steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends