class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};

        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}}); // :)
        while(!pq.empty()){
            int minRemoved = pq.top().first;
            int r = pq.top().second.first; 
            int c = pq.top().second.second;
            pq.pop();
            for(int i = 0; i<4;i++){
                int newR = r + row[i];
                int newC = c + col[i];
                if(newR >=0 && newR < n && newC >=0 && newC <m ){
                    int obstacle = grid[newR][newC];
                    if(minRemoved + obstacle < dist[newR][newC]){
                        dist[newR][newC] = minRemoved + obstacle;
                        pq.push({minRemoved + obstacle , {newR,newC}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};