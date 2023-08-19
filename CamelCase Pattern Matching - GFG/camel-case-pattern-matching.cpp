//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> arr, string pat) {
        // code here
        vector<string> ans;
        int p=pat.size();
        
        for(int i=0;i<n;i++){
            bool found=false;
            int k=0;
            for(int j=0;j<arr[i].size();j++){
                char curr_char=arr[i][j];
                if(curr_char>='A' && curr_char<='Z'){
                    if(k==p) break;
                    if(arr[i][j]==pat[k]){
                        k++;
                        found=true;
                    }
                    else{
                        found=false;
                        break;
                    }
                    
                }
            }
            if(found==true && k==p){
                ans.push_back(arr[i]);
            }
        }
        if(ans.empty()){
            ans.push_back("-1");
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends