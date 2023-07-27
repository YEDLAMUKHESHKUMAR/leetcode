//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int N) 
    { 
        int j=N-1,min_element=0;
        int n=arr[N-1]+1;      // don't try to calculate % with size of the array...it will cause 0 if any element is greated than n
        for(int i=0;i<N;i++){
            
            if(i%2==0){
                arr[i]+=(arr[j]%n)*n;
                j--;
            }
            else{
                arr[i]+=(arr[min_element]%n)*n;
                min_element++;
            }
            
        }
        for(int i=0;i<N;i++){
            arr[i]/=n;
        }
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends