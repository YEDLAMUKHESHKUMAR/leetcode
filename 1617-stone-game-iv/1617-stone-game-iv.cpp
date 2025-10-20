class Solution {
public:
    int solve(int n, int turn, vector<vector<int>>& dp){
        if(n == 0){
            if(turn == 0) return 2; // alice has zero moves...so bob winner..
            return 1;
        }
        if(dp[n][turn] != -1) return dp[n][turn];
        for(int i = 1; i <= (sqrt(n)) ;i++){
            int res = solve(n - (i * i) , !turn, dp);
            if((turn == 0 && res == 1)) return dp[n][turn] =  1;
            if(turn == 1 && res == 2) return dp[n][turn] =  2;
        }
        if(turn == 0) return dp[n][turn] = 2;
        return dp[n][turn] = 1;
    }
    bool winnerSquareGame(int n) {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int> (3, -1));
        int res = solve(n, 0, dp);
        if(res == 1) return true;
        return false;
    }
};