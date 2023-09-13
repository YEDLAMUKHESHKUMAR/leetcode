//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        
        // code here
        if(s==0 && n>1) return "-1";
        string ans;
        int nines=s/9;
        int remainingSum=s%9;
        int r = remainingSum==0?0:1;
        if(n<(nines+r)){
            return "-1";
        }
        while(n!=0){
            if(s>=9){
                ans+="9";
                s-=9;
            }
            else {
                ans+= to_string(s);
                s-=s;
            }
            n--;
        }
        // if(n!=0){
        //     ans+=to_string(remainingSum);
        //     n--;
        // }
        // while(n!=0){
        //     ans+='0';
        //     n--;
        // }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends