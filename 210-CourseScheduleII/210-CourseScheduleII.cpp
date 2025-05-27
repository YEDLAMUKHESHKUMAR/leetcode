// Last updated: 5/27/2025, 11:55:22 AM
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ind(n , 0);
        vector<int> graph[n];
        for(auto adj : pre){
            graph[adj[1]].push_back(adj[0]);
            ind[adj[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < n;i++){
            if(ind[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adj : graph[node]){
                if(ind[adj] == 0) break;
                ind[adj]--;
                if(ind[adj] == 0) q.push(adj);
            }
        }
        if(ans.size() != n) return {};
        return ans;

    }
};