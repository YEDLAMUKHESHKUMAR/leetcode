//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> bracketNumbers(string s)
	{
	    // Your code goes here
	    int count=0;
	    stack<int> bracket_count;
	    vector<int> ans;
	    int n=s.size();
	    for(int i=0;i<n;i++){
	        if(s[i]=='('){
	            count++;
	            bracket_count.push(count);
	            ans.push_back(count);           
	        }
	        else if(s[i]==')'){
	            ans.push_back(bracket_count.top());
	            bracket_count.pop();
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.bracketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends