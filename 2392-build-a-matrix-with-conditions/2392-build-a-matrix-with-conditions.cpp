class Solution {
public:
    void dfs(int& u, vector<int>& vis, unordered_map<int, vector<int>>& graph,stack<int>&st, bool& cycle) {
        vis[u] = 2;
        for(auto i:graph[u]){
            if(!vis[i]){
                dfs(i, vis, graph, st, cycle);
            }
            else if(vis[i] == 2) {
                cycle = true;
                return;
            }
        }
        vis[u] = 1;
        st.push(u);
    }
    vector<int> topo(vector<vector<int>> edj,int k){
        unordered_map<int, vector<int>> graph;
        for(auto i:edj){
            int u = i[0];
            int v = i[1];
            graph[u].push_back(v);
        }
        bool cycle = false;
        vector<int> vis(k+1,0);
        stack<int> st; 
        vector<int> order;
        for(int i = 1;i<=k;i++){
            if(!vis[i]){
                dfs(i, vis, graph, st, cycle);
                if (cycle == true) {
                    return {};
                }
            }
        }
        while (!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        // don't reverse the order... while creating matrix...it should be in same order for test case 1 : row [3,1,2] 
    // col [3,2,1]
        return order; 
        

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> ord_rows = topo(rowConditions, k);
        vector<int> ord_cols = topo(colConditions, k);
        if (ord_rows.empty() || ord_cols.empty()) {
            return {}; 
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (ord_rows[i] == ord_cols[j]) {
                    matrix[i][j] = ord_rows[i]; 
                }
            }
        }
        return matrix;
    }
};