#define pii pair<int,int>
class Solution {
public:
    vector<int> row = {0,0,1,-1};
    vector<int> col = {1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
        // I think , i got it...after watching topic...thought it was dp , but we can apply dp only on DAG
        // TRY BFS or DIJKSTRA, not sure if it works, need to try 
        // we just need min cost, not path...so move from 0,0 to last, using bfs, if arrow is same as you are moving, 0 cost, other wise 1cost, track the min cost using dijkstra....edit: worked :)

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> minCost(n , vector<int> (m , INT_MAX));
        priority_queue< pair<int,pii>, vector<pair<int,pii>>, greater<pair<int, pii>>> pq;

        pq.push({0,{0,0}});
        minCost[0][0] = 0;
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();
            if(r == n-1 && c == m-1) return cost;
            for(int i = 0; i<4;i++){
                int newRow = r + row[i];
                int newCol = c + col[i];
                if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0){
                    int needShift = 0;
                    if(i + 1 != grid[r][c]) needShift++;
                    if(cost + needShift < minCost[newRow][newCol]){
                        minCost[newRow][newCol] = cost + needShift;
                        cout<<newRow<<" "<<newCol;
                        pq.push({cost + needShift, {newRow, newCol}});
                    }
                }
            }
        }
        return minCost[n-1][m-1];
    } 
};