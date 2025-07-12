// Last updated: 7/12/2025, 10:07:35 PM
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        // :)
        int cost = 0;
        int r1 = startPos[0], r2 = homePos[0];
        int c1 = startPos[1], c2 = homePos[1];
        
        if(r1 < r2){
            for(int i = min(r1, r2) + 1 ; i <= max(r1, r2) ; i++){
                cost += rowCosts[i];
            }
        }
        if(r1 > r2){
            for(int i = max(r1, r2) - 1  ; i >= min(r1, r2) ; i--){
                cost += rowCosts[i];
            }
        }
        if(c1 < c2){
            for(int i = min(c1, c2) + 1 ; i<= max(c1, c2) ; i++){
                cost += colCosts[i];
            }
        }
        if(c1 > c2){
            // cout<<1;
            for(int i = max(c1, c2) - 1  ; i >= min(c1, c2) ; i--){
                cost += colCosts[i];
            }
        }
        return cost;

    }
};