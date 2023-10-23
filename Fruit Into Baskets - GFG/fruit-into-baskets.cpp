//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &arr) {
        int c=0;
        int j=0;
        int maxBaskets = 2;
        int maxFruits = 0 ;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(mp[arr[i]]==1){
                c++;
            }
            while(j<n && c > maxBaskets){
                mp[arr[j]]--;
                if(mp[arr[j]]==0){
                    c--;
                }
                j++;
            }
            maxFruits = max(maxFruits,i - j + 1 );    
        }
        return maxFruits;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends