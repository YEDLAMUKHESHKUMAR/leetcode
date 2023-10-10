//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution 
{
    public:
    int canAllocate(int arr[],int n,int &mid){
            int students=1;
            int sum = 0;
            for(int i=0;i<n;i++){
                if( arr[i] + sum <= mid){
                    sum+=arr[i];
                }
                else{
                    students++;
                    sum=arr[i];
                }
            }
            return students;
        }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n) return -1;
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int low=maxi, high=sum;
        while(low<=high){
            int mid = (low+high)/2;
            int students = canAllocate(arr,n,mid);
            if(students > m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends