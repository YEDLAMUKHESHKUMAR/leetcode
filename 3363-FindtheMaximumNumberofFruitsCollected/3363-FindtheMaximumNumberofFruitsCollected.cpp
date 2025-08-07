// Last updated: 8/7/2025, 10:34:56 AM
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        int n = fruits.size();
        if(i == n - 1 && j == n - 1) return dp[i][j] = 0;
        if(i < 0 || i >= n || j < 0 || j>= n || j <= i) return -1e8;
        if(dp[i][j] != -1) return dp[i][j];
        int leftDiag = fruits[i][j] + solve(i + 1, j - 1, fruits, dp);
        int down = fruits[i][j] +  solve( i + 1, j, fruits, dp  );
        int rightDiag = fruits[i][j] +  solve(i + 1, j + 1, fruits, dp);

        return dp[i][j] = max({leftDiag, down, rightDiag}); 
    }


    
    int solve2(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        int n = fruits.size();
        if(i == n - 1 && j == n - 1) return 0;
        if(i < 0 || i >= n || j < 0 || j>= n || j >= i) return -1e8;
        if(dp[i][j] != -1) return dp[i][j];
        int upRightDiag = fruits[i][j] + solve2(i - 1, j + 1, fruits, dp);
        int right = fruits[i][j] +  solve2( i , j + 1, fruits, dp  );
        int rightDiag =  fruits[i][j] + solve2(i + 1 , j + 1, fruits, dp);

        return dp[i][j] = max({upRightDiag, right, rightDiag}); 
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        // easy if u figure out exactly n - 1 moves part :)...
        int n = fruits.size();
        int firstChild = 0;
        for(int i = 0; i < n ;i++){
            firstChild += fruits[i][i];
            fruits[i][i] = 0;  
        }
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int secondChild = solve(0, n - 1, fruits, dp);
        
        int thirdChild = solve2(n - 1, 0, fruits, dp);

        return firstChild + secondChild + thirdChild;


    }
};














/*
   . _ _ _ _ _ _
   _ . _ _ _ _ _
   _ _ . _ _ _ _
   _ _ _ . _ _ _
   _ _ _ _ . _ _
   _ _ _ _ _ . _
   _ _ _ _ _ _ .

   5, 5




*/






