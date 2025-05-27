// Last updated: 5/27/2025, 5:34:03 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<int> invGraph[n];
        vector<vector<int>> invGraph(n);
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n ;i++){
            for(auto adj : graph[i]){
                invGraph[adj].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n ;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adj : invGraph[node]){
                inDegree[adj]--;
                if(inDegree[adj] == 0) q.push(adj);
            }

        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};