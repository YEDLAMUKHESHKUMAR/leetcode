class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,-1,0,1}; // :)
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        while(!pq.empty()){
            int currTime = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i =0;i<4;i++){
                int newR = r + row[i];
                int newC = c + col[i];
                if(newR >= 0 && newR <n && newC >=0 && newC < m){
                    int needTime = grid[newR][newC] - currTime;  // check how time is changing for even and odd diff's... 
                    int waitTime  = 0;
                    if(needTime > 0){
                        waitTime += needTime;
                        if(needTime % 2 == 0) waitTime++;
                    }
                    else waitTime++;
                    if(waitTime + currTime < dist[newR][newC]){
                        dist[newR][newC] = waitTime + currTime;
                        pq.push({waitTime + currTime, {newR,newC}});
                    }

                }
            }
              
        }
        return dist[n-1][m-1];
        


    }
};