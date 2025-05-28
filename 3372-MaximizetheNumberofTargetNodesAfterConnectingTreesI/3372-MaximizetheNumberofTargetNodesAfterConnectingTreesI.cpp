// Last updated: 5/28/2025, 2:25:33 PM
class Solution {
public:

    int bfs(int ithnode, int levels, vector<int> graph[]){
        if(levels < 0) return 0;
        queue<pair<int,int>> q;
        q.push({ithnode, -1});
        int ans = 1;
        while(!q.empty() && levels--){
            int qs = q.size();
            for(int i = 0 ; i < qs ;i++){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto adj : graph[node]){
                    if(adj != parent) {
                        ans++;  
                        q.push({adj, node});
                    }
                }

            }
        }
        return ans;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // k = 0;
        int n = edges1.size() ;
        int m = edges2.size() ;
        vector<int> graph1[n + 1];
        vector<int> graph2[m + 1];
        for(auto i : edges1){
            graph1[i[0]].push_back(i[1]);
            graph1[i[1]].push_back(i[0]);
        }
        for(auto i : edges2){
            graph2[i[0]].push_back(i[1]);
            graph2[i[1]].push_back(i[0]);
        }

        // vector<int> g2(m + 1, 0);
        int maxi = 0;
        vector<int> ans;
        for(int i = 0; i<= m; i++){
            int nodes = bfs(i, k - 1, graph2);
            // g2[i] = nodes;
            // cout<<nodes<<" ";
            maxi = max(maxi, nodes );
        }
        // cout<<endl;
        for(int i = 0; i <= n;i++){
            int nodes = bfs(i, k, graph1)  ;
            // cout<<nodes<<" ";
            ans.push_back(nodes + maxi);
        }
        return ans;
        


    }
};