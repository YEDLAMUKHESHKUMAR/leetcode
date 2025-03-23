// Last updated: 3/23/2025, 9:53:31 AM
class Solution {
public:
    void solve(int node, unordered_map<int,vector<int>> &graph, vector<int> &vis){
        vis[node] = 1;
        for(auto adj: graph[node]){
            if(!vis[adj]){
                solve(adj, graph, vis);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        // unordered<int,vector<int>> graph;
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < n;i++){
            vector<int> mp1(101, 0);
            for(auto ele : nums[i]) mp1[ele]++;
            
            for(int j = i + 1; j < n; j++){
                vector<int> mp2(101, 0);
                int undhi = 0;
                for(auto ele : nums[j]){
                    if(mp1[ele] > 0 && mp2[ele] == 0){
                        mp2[ele] = 1;
                        undhi++;
                    }
                }
                if(undhi >= k){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int components= 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                components++;
                solve(i, graph, vis);
            }
        }
        return components;
        
        
    }
};