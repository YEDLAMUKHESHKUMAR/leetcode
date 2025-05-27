// Last updated: 5/27/2025, 4:25:34 PM
class Solution {
public:
    bool solve(int node, vector<vector<int>>& graph, vector<int> &safe, vector<int> &vis, vector<int> &pathVis){
        if(safe[node] == false) return false;
        vis[node] = 1;
        pathVis[node] = 1;
        bool isSafe = true;
        for(auto adj : graph[node]){
            if(!vis[adj]){
                if(solve(adj, graph, safe, vis, pathVis) == false ){
                    isSafe = false;
                    break;
                }
            }
            else if(pathVis[adj] == 1){
                isSafe = false;
                break;
            }
            else{
                isSafe = safe[adj];
                if(isSafe == false) break;
            }
        }
        pathVis[node] = 0;
        safe[node] = isSafe;
        return isSafe;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe(n, true);
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> ans;
        for(int i = 0; i < n ;i++){
            if(!vis[i]){
                solve(i, graph, safe, vis, pathVis);
                // if(safe[i]) ans.push_back(i); 
            }
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};