class Solution {
public:
    int solve(int i,int target,vector<int> &dp){
        if(target == 0) return 0;
        if((i*i) > target) return 1e8;
        if(dp[target] != -1) return dp[target];
        int right = solve(i+1,target,dp);

        int left = 1e9;
        if((i*i) <= target){
            left = 1 + solve(i,target - (i*i),dp);
        }
        return dp[target] = min(left,right);
        
    }
    int numSquares(int n) {
        // return start;
        vector<int> dp(n + 1, -1);
        return solve(1,n,dp);
    }
};