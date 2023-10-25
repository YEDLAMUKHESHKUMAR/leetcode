//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int atmost(int n,vector<int> &arr , int k){
        int numberOfOdds = 0;
        int i = 0 ;
        int atmost_K_Subarrays = 0 ;
        for(int j=0;j<n;j++){
            if(arr[j] % 2 != 0 ){
                numberOfOdds++;
            }
            while(i < n && numberOfOdds > k ){
                if(arr[i] % 2 != 0 ){
                    numberOfOdds--;
                }
                i++;
            }
            atmost_K_Subarrays += j - i + 1 ;
        }
        return atmost_K_Subarrays;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return atmost(n,nums,k) - atmost(n,nums,k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends