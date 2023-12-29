class Solution {
public:
    int solve(int ind,int d,vector<int> &jd,vector<vector<int>> &dp){
        int n = jd.size(); 
        if(d==1){
            int maxi = jd[ind];
            for(int i=ind;i<n;i++){                
                maxi = max(maxi,jd[i]);
            }
            return dp[d][ind] = maxi;
        }
        if(dp[d][ind] != -1) return dp[d][ind];

        int maxD = jd[ind] , finalAns = INT_MAX;
        for(int i=ind;i<=n-d;i++){
            maxD = max(maxD,jd[i]);
            int ans = maxD + solve(i+1,d-1,jd,dp);
            finalAns = min(finalAns , ans);
        }
        return dp[d][ind] = finalAns;


    }
    int minDifficulty(vector<int>& jd, int d) {
        // notes
        int n = jd.size();
        if(n < d )return -1;

        vector<vector<int>> dp( d + 1 , vector<int> (n,-1));
    
        return solve(0,d,jd,dp);

    }
};