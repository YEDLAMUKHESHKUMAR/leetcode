//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    bool unsorted=false;
	    int current_index;
	    int left_index=0;
	    int right_index=0;
	    int min=INT_MAX;
	    int max=arr[0];
	    int current_element;
	    for(int i=1;i<n;i++){
	        current_element=arr[i];
	        current_index=i;
	        if(current_element<max){
	            if(unsorted==false){
	                left_index=current_index-1;
	                unsorted=true;
	            }
	            if(current_element<min){
	                min=current_element;
	            }
	            right_index=current_index;
	        }
	        else{
	            max=current_element;
	        }
	    }
	    
	    for(int i=left_index;i>=0;i--){
	        current_element=arr[i];
	        current_index=i;
	        if(current_element>min){
	            left_index=current_index;
	        }
	    }
	    return {left_index,right_index};
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends