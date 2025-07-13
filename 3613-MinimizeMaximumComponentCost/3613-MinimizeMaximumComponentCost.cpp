// Last updated: 7/13/2025, 9:43:43 AM
class Solution {
public:
    void dfs(int node, int mid, unordered_map<int, vector<pair<int,int>>>& graph, vector<int>& vis){
        vis[node] = 1;
        // cout<<node<<" ";

        for(auto adj : graph[node]){
            if( mid < adj.second  ) continue;
            if(!vis[adj.first]) dfs(adj.first, mid, graph, vis);
        }
    }
    bool solve(int n,int mid,int k, unordered_map<int, vector<pair<int,int>>>& graph ){
        vector<int> vis(n + 1 , 0);
        int connectedComponents = 0;
        for(int i = 0; i < n ;i++){
            if(!vis[i]){
                dfs( i, mid, graph , vis);
                connectedComponents++;
            }
        }
        if(connectedComponents <= k) return true;
        return false;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
        int maxi = 0;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            maxi = max(maxi, cost);
            graph[u].push_back({v ,cost});
            graph[v].push_back({u ,cost});
        }
        int low = 0, high = maxi + 1, ans = -1;
        while(low <= high){
            int mid = ( low + high) / 2;
            if(solve(n, mid, k, graph)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};