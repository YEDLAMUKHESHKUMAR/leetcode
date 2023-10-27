//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            // string ipAddress="";
            bool containIP = false;
            int dots = 0;
            int ipAddress = 0;
            int isInRange;
            int n=s.size();
            if(n<7 || (s[0]=='0' && s[1]!='.') || s[0]=='.' || s[n-1]=='.') return 0;
            for(int i=0;i<n;i++){
                if(s[i]>='a' && s[i]<='z') return 0;
                if(s[i]=='.'){
                    dots++;
                    if(containIP == false || dots>3) return 0;
                    if(s[i+1]=='0'){
                        if(i+2<n && s[i+2]!='.') return 0;
                    }
                    if(ipAddress<0 || ipAddress>255) return 0;
                    ipAddress = 0;
                    containIP = false;
                    
                }
                else{
                    containIP = true ;
                    int num = s[i] - '0';
                    ipAddress = ipAddress*10 + num;
                }
                
            }
            if(dots<3) return 0;
            if(ipAddress<0 || ipAddress>255) return 0;
            return 1;
            
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends