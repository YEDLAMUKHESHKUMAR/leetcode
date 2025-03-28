// Last updated: 3/28/2025, 10:19:31 AM
class Solution {
public:
    vector<int> row = {0, -1, 0, 1};
    vector<int> col = {1, 0 ,-1, 0};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // got it.. :) , just sort the queries...
        // lol , took directions wrong...wasted 2 WA
        vector<pair<int,int>> q ;
        int n = grid.size(), m = grid[0].size(), qs = queries.size(), points = 0;
        vector<int> ans(qs,0);
        vector<vector<int>> vis(n, vector<int> (m , 0) );
        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> > pq;

        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        for(int i = 0; i < qs;i++){
            int currElement = q[i].first;
            while(!pq.empty()){
                int top = pq.top().first;
                if(top >= currElement) break;
                int r = pq.top().second.first;
                int c = pq.top().second.second;
                pq.pop();
                points++;
                for(int k = 0; k < 4 ; k++){
                    int newRow = r + row[k];
                    int newCol = c + col[k];
                    if(newRow >=0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]){
                        pq.push({grid[newRow][newCol] ,  { newRow, newCol }});
                        vis[newRow][newCol] = 1;
                    }
                }
            }
            ans[q[i].second] = points;
        }
        return ans;

    }
};