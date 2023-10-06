//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        unordered_map<char,int> mp;
        int temp=k-1,ans=0;
        int distinct=0;
        for(int i=0;i<k;i++){
            mp[s[i]]++;
            if(mp[s[i]]==1) distinct++;
        }
        if(distinct==temp) ans++;
        for(int i=k;i<s.size();i++){
            mp[s[i-k]]--;
            if(mp[s[i-k]]==0) {
                distinct--;
            }
            mp[s[i]]++;
            if(mp[s[i]]==1) {
                distinct++;
            }
            if(distinct==temp) ans++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends