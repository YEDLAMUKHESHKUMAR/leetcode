//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string str="",ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                ans+=str+'.';
                str="";
            }
            else
            {
                str=s[i]+str;
            }
        }
        ans+=str;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends