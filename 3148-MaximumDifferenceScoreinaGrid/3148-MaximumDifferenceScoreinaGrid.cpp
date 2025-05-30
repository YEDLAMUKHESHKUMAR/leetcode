// Last updated: 5/30/2025, 10:35:17 PM
class Solution {
public:
    int solve(int day, int city, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, vector<vector<int>> &dp ){
        if(day >= k) return 0;
        if(dp[day][city] != -1) return dp[day][city];
        int stay = stayScore[day][city] + solve(day + 1, city, k, stayScore, travelScore, dp);
        int move = 0;
        for(int dest = 0; dest < travelScore[city].size(); dest++){
            if(city != dest){
                move = max(move, travelScore[city][dest]  + solve(day + 1, dest, k, stayScore, travelScore, dp) );
            }
        }
        return dp[day][city] = max(stay, move);

// return 1;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {

        int maxi = 0;
        vector<vector<int>> dp(k + 1, vector<int> (n + 1, -1));
        for(int i = 0; i<stayScore[0].size();i++){
            maxi = max(maxi,  solve( 0, i, k, stayScore, travelScore , dp)  );
        }

        return maxi;
        //  you can do it... it is what you think it is....

        // if you want to stay in city ... you must take it from first array... but if you want to move... 
        // u have to take it from the other array..
        // at first on the 0th day.. you can take any city from stayScore[0]... then follow the rules..


        



    }
};