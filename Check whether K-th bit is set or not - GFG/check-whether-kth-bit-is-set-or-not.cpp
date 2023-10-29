//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // when you perform right shift operation k times , it comes to first position (LSB) . then you can easily
        // check whether it is a set bit or not by performing Bitwise and operation b/w rightShiftedBit and 1
        // if you get 1 after performin AND , Your bit is Set otherwise , Not . 
        // Eg : n = 6
        // bit ->  0110 ----> right shift by k=2 times ----> 0001 ----> perform 0001 & 0001 which results True
        return n>>k & 1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;//taking testcases
	while(t--)
	{
	    long long n;
	    cin>>n;//input n
	    int k;
	    cin>>k;//bit number k
	    Solution obj;
	    if(obj.checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}
// } Driver Code Ends