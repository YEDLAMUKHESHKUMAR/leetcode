class Solution {
public: 
    int dfs(int node, int dep, unordered_map<int,vector<int>>& graph, vector<int>& depth, vector<int>& subtrees){
        depth[node] = dep;
        int size = 0;
        for(auto adj : graph[node]){
            if(depth[adj] == -1){
                size += dfs(adj, dep + 1, graph, depth, subtrees);
            }
        }

        subtrees[node] += size;
        return size + 1;


    }
    int dfs2(int node, int parent, int n, unordered_map<int, vector<int>>& graph, vector<int>& subtrees, vector<int>& ans){
        

        int sizeOfCurrentSubtree = subtrees[node] + 1;
        if(node != 0){
            ans[node] = ans[parent] - sizeOfCurrentSubtree + (n - sizeOfCurrentSubtree);
        }

        for(auto adj : graph[node]){
            if(ans[adj] == -1){
                dfs2(adj, node, n, graph, subtrees, ans);
            }
        }
        return 0;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < n-1 ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> depth(n, -1);
        vector<int> subtrees(n, 0);
        dfs(0, 0, graph, depth, subtrees);
        vector<int> ans(n, -1);
        ans[0] = 0;
        for(int i = 0; i < n;i++) ans[0] += depth[i];
        dfs2(0, 0, n, graph, subtrees, ans);
        return ans;

    }
};