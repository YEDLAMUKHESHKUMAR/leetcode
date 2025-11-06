class Solution {
public:
    void solve(int node, int put, unordered_map<int, vector<int>>& graph, vector<int>& vis, unordered_map<int, set<int>> &parent, unordered_map<int,int>& match){
        parent[put].insert(node);
        match[node] = put;
        vis[node] = 1;
        for(auto adj : graph[node]){
            if(!vis[adj]){
                solve(adj, put, graph, vis, parent, match);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& q) {
        int n = connections.size();
        int qs  = q.size();
        unordered_map<int, vector<int>> graph;
        for(int i = 0 ; i < n; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        unordered_map<int, int> offline;
        unordered_map<int, int> match;
        unordered_map<int, set<int>> parent;

        vector<int> vis(c + 1, 0);
        int par = 1;
        for(int i = 1 ; i<= c ; i++){
            if(!vis[i]){
                solve(i, par, graph, vis, parent, match);
                par++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < qs ; i++){
            int type = q[i][0];
            int station = q[i][1];
            if(type == 1){
                if(offline.find(station) == offline.end()){
                    ans.push_back(station);
                }
                else{
                    int gotParent = match[station];
                    if(parent[gotParent].empty()){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(*parent[gotParent].begin());
                    }
                }
            }
            else{
                int parrr = match[station];
                offline[station] = parrr;
                parent[parrr].erase(station);
                // remove
            }
        }
        return ans;


    }
};