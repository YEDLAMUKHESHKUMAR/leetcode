class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> graph;
    vector<int> solve(int node){
        vis[node] = 1;
        vector<int> path, longestPath;
        for(auto adj : graph[node]){
            if(!vis[adj]){
                path = solve(adj);
                if(path.size() > longestPath.size()){
                    longestPath = move(path);
                }
            }
        }
        vis[node] = 0;
        longestPath.push_back(node);
        return longestPath;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vis.resize(n);
        graph.resize(n);
        // unordered_map<int,vector<int>> graph;
        for(auto edj : edges){
            int u = edj[0];
            int v = edj[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> path = solve(solve(0)[0]);
        // path = solve(path[0]);

        if(path.size() % 2 == 0){
            return {path[path.size() / 2], path[path.size() / 2 - 1] };
        }
        return {path[path.size() / 2]};
    }
};