//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

int findEqualPoint(int arr[], int n) ;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n]={0};
		for(int i = 0; i < n; i++)
		cin>>arr[i];
		
		cout<< findEqualPoint(arr, n) <<endl;
	}
	
	return 0;
}

// } Driver Code Ends


int findEqualPoint(int arr[], int n) 
{
    // Your code goes here
    // if(n==1 || n==2) return 0;
    int prefix_elements[n];
    int suffix_elements[n];
    int front_value=arr[0];
    int back_value=arr[n-1];
    int front=0;
    int back=0;
    prefix_elements[0]=0;
    suffix_elements[n-1]=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=front_value){
            front_value=arr[i];
            front++;
        }
        if(arr[n-i-1]!=back_value){
            back_value=arr[n-i-1];
            back++;
        }
        prefix_elements[i]=front;
        suffix_elements[n-i-1]=back;
    }
    for(int i=0;i<n;i++){
        if(prefix_elements[i]==suffix_elements[i]){
            return i;
        }
    }
    return -1;
}