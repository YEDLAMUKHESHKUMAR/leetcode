// Last updated: 5/27/2025, 11:28:14 AM
class Solution {
public:

    bool solve(int node, vector<int> &vis, vector<int> &pathVis, vector<int> graph[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto adj : graph[node]){ 
            if(!vis[adj]){
                if(solve(adj, vis, pathVis, graph)) return true;
            }
            else if(pathVis[adj] == 1) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> graph[n];
        for(auto i : pre){
            graph[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                if( solve(i, vis, pathVis, graph) ) return false;
            }
        }
        return true;

    }
};