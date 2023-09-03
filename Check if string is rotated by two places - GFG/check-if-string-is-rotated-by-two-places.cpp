//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string s1, string s2)
    {
        // Your code here
        // onamaz
        // azonam
        int n1=s1.size(),n2=s2.size();
        int i=0,j=0;
        if(n1!=n2) return false;
        if(n1==1 && n2==1){
            if(s1[0]==s2[0]) return true;
            return false;
        } 
        
        bool left=false,right=true;
        if(s1[0]==s2[n2-2]){
            if(s1[1]==s2[n2-1]){
                i+=2;
                n2-=2;
                left=true;
                
            }
            else{
                left=false;
            }
        }
        else if(s1[n1-1]==s2[1]){
            if(s1[n1-2]==s2[0]){
                right=true;
                j+=2;
                n1-=2;
            } 
            else right=false;
        }
        if(left==false && right==false) return false;
        while(i<n1 && j<n2){
            if(s1[i]!=s2[j]) return false;
            i++;
            j++;
        }
        return true;
        
        

    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends