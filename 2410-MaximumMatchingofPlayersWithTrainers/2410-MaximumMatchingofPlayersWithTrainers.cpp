// Last updated: 7/13/2025, 10:02:56 AM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int n = players.size();
        int m = trainers.size();
        int i = 0 ,j = 0, ans = 0;
        while(i < n && j < m){
            while(j < m && players[i] > trainers[j]){
                j++;
            }
            if(j < m) ans++;
            i++;
            j++;
        }
        return ans;
    }
};