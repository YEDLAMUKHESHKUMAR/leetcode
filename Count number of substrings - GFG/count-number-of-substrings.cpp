//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int solve(string &s,int k){
        int i=0,j=0;
        int n=s.size();
        long long int ans=0;
        vector<int> chars(26,0);    
        int distinct=0;
        while(i<n){
            chars[s[i]-'a']++;
            if(chars[s[i]-'a']==1){
                distinct++;
            }
            while(distinct>k){
                chars[s[j]-'a']--;
                if(chars[s[j]-'a']==0){
                    distinct--;
                }
                j++;
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	
    	//              ******* exactly k = atmost k - atmost k-1 *******
    	
    	// while we are using sliding window approach ...it is calculating all the substrings having k and
    	// along with <k  distinct characters ..since we want only k distinct ...we subtract atmost k - atmost k-1
    	// eg: abaaddccdbaca k=3 , in our algorithm we are considering all the substrings which consists 3,2,1
    	// disctinct characters...means we are considering the substrings even it has less than k distinct characters
    	// so just delete those <k characters...just consider k as k-1..and then apply same algorithm then subtract it 
    	// from atmost k distinct -----> (3,2,1)-(2,1)--->(3);
    	
    	
    	return solve(s,k)-solve(s,k-1);
    	
    	
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends