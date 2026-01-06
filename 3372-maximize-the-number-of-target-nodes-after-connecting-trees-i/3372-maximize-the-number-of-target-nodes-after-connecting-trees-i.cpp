class Solution {
public:
    int bfs(int node, int k, unordered_map<int, vector<int>>& graph){
        int n = graph.size();
        queue<int> q;
        vector<int> vis(n + 2, 0);
        q.push(node);
        vis[node] = 1;
        int ans = 1;
        while(!q.empty() && k--){

            int qs = q.size();
            for(int i = 0 ; i < qs;i++){
                int currNode = q.front();
                q.pop();
                for(auto adj : graph[currNode]){
                    if(!vis[adj]){
                        vis[adj] = 1;
                        q.push(adj);
                        ans++;
                    }
                }

            }
        }
        return ans;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        unordered_map<int, vector<int>> graph1; 
        unordered_map<int, vector<int>> graph2; 
        for(auto i : edges1){
            int u = i[0];
            int v = i[1];
            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }
        for(auto i : edges2){
            int u = i[0];
            int v = i[1];
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }

        int maxAnsFromTree2 = 0;
        for(int i = 0 ;i <= m ;i++  ){
            int currAns = bfs(i, k - 1, graph2);
            maxAnsFromTree2 = max(maxAnsFromTree2, currAns);
        }
        cout<<maxAnsFromTree2<<endl;
        vector<int> ans(n+1, 1);

        if(k == 0) return ans;
        for(int i = 0; i <= n;i++){
            int currAns = bfs(i, k, graph1);
            ans[i] = currAns + maxAnsFromTree2;
        }
        return ans;


    }
};