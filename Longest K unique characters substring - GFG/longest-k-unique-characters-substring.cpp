//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0,j=0;
        unordered_map<char,int> mp;
        int n=s.size();
        int ans=-1;
        while(i<n){
            if(mp[s[i]]==0){
                k--;
            }
            mp[s[i]]++;
            if(k==0){
                ans=max(ans,i-j+1);
            }
            while(k<0){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    k++;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends