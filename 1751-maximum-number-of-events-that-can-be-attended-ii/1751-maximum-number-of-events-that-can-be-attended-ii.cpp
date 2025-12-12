class Solution {
public:
    int bs(int st, int target, vector<vector<int>>& events){
        int n = events.size();
        int low = st, high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(events[mid][0] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int solve(int i, int k, vector<vector<int>>& events, vector<vector<int>>& dp){
        int n = events.size();
        if(i >= n || k == 0 ) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int take = 0 ;
        int findNext = bs(i + 1, events[i][1], events);
        if(k > 0) take = events[i][2] + solve(findNext, k - 1, events, dp); 
        int notTake = solve(i + 1, k, events, dp);
        return dp[i][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1 , vector<int> (k + 1, -1));
        return solve(0, k, events, dp);
    }
};