//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int i=1,j=n-2;
        long long leftMax=arr[0],rightMax=arr[n-1];
        long long ans=0;
        while(i<=j){
            if(leftMax<rightMax){
                if(arr[i]>=leftMax){
                    leftMax=arr[i];
                }
                else{
                    ans+=(leftMax-arr[i]);
                }
                i++;
            }
            else{
                if(arr[j]>=rightMax){
                    rightMax=arr[j];
                }
                else{
                    ans+=(rightMax-arr[j]);
                }
                j--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends