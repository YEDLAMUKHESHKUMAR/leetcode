// Last updated: 8/4/2025, 9:50:50 AM
class Solution {
public:
    vector<int> row = {0,-1,0,1};
    vector<int> col = {-1,0,1,0};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> minTime(n + 1, vector<int> (m + 1, INT_MAX));
        priority_queue< pair<int,pair<int,pair<int,int>>>, vector<pair<int,pair<int,pair<int,int>>>>, greater<pair<int,pair<int,pair<int,int>>>> > pq;

        pq.push({0, {0,{0,0}}});
        minTime[0][0] = 0;
        bool addTwo = false;
        // return 1;
        while(!pq.empty()){
            int time = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second.first;
            int addTwo = pq.top().second.second.second;
            
            pq.pop();
            for(int dir = 0 ; dir< 4; dir++){
                int newRow = r + row[dir];
                int newCol = c + col[dir];
                if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0){
                    int need = max(time , moveTime[newRow][newCol] ) + + addTwo + 1;
                    if(need < minTime[newRow][newCol]){
                        pq.push({need, {newRow, {newCol, !addTwo } }});
                        minTime[newRow][newCol] = need;
                    }
                }
            }

        }
        return minTime[n - 1][m - 1];

    }
};