class Solution {
public:
    bool solve(int i , int n, vector<int> &arr, vector<int> &vis, vector<int> &dp){
        vis[i] = 1;
        
        if(arr[i] == 0) return true;
        if(dp[i] != -1) return dp[i];
        bool left = false, right = false;
        if(i - arr[i] >= 0 && vis[i - arr[i]] == 0){
            left = solve(i - arr[i], n, arr, vis, dp);
        }
        if(i + arr[i] < n && vis[i + arr[i]] == 0){
            right = solve(i + arr[i], n, arr, vis, dp);
        }

        return dp[i] = left | right;
        vis[i] = 0;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, -1);
        vector<int> vis(n, 0);
        return solve(start, n, arr,vis,dp);
         
    }
};