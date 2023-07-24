//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> arr, int n) {
        long long fact=1;
        long long max_number=arr[0];
        for(int i=1;i<n;i++){
            if(max_number<arr[i]){
                max_number=arr[i];
            }
        }
        vector<long long> all_factorials;
        for(int i=1;i<=max_number;i++){
            fact=(fact*i)%1000000007;
            all_factorials.push_back(fact);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i]=1;
            }
            else{
                arr[i]=all_factorials[arr[i]-1];
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends