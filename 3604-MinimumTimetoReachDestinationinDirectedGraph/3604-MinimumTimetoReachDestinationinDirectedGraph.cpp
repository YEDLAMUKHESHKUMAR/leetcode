// Last updated: 7/5/2025, 10:06:40 PM
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector< pair<int,pair<int,int>>>> graph;
        vector<int> minDist(n + 1, INT_MAX);
        // src, {dest , {st, end}}
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int st = i[2];
            int end = i[3];
            graph[u].push_back({v, {st, end}});
        }
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq; 
        pq.push({0, 0});
        minDist[0] = 0;
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == n - 1) {
                return time;
            }
            
            for(auto adj : graph[node]){
                int tempTime = time;
                int v = adj.first;
                int st = adj.second.first;
                int end = adj.second.second;
                if(tempTime > end) continue;

                if(tempTime < st){
                    tempTime = st;
                }
                
                if(tempTime + 1 < minDist[v]){
                    minDist[v] = tempTime + 1;
                    pq.push({tempTime + 1, v});
                }
                
                
            }
            
        }
        
        return -1;
    }
};