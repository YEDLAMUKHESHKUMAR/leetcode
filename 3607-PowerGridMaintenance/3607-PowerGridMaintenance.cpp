// Last updated: 7/6/2025, 10:46:17 AM
class Solution {
public: 
    void solve(int node, int uniqueId, unordered_map<int, vector<int>>& graph, unordered_map<int, set<int>>& grp, unordered_map<int, int>& belongsTo, vector<int>& vis){
        vis[node] = 1;
        grp[uniqueId].insert(node);
        belongsTo[node] = uniqueId;
        for(auto adj : graph[node]){
            if(!vis[adj]){
                solve(adj, uniqueId, graph, grp, belongsTo, vis);
            }
        } 
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& q) {
        unordered_map<int,vector<int>> graph;
        for(auto i : connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> vis( c + 1 , 0);
        unordered_map<int, set<int>> grp;
        unordered_map<int, int> belongsTo;
        int uniqueId = 1;
        for(int i = 1; i <= c; i++){
            if(!vis[i]){
                solve(i, uniqueId, graph, grp, belongsTo, vis);
                uniqueId++;
            }
        }
        int qs = q.size();
        vector<int> ans;
        for(int i = 0; i < qs ;i++){
            int type = q[i][0];            
            int node = q[i][1];            
            int itsComponent = belongsTo[node];
            if(type == 2){
                grp[itsComponent].erase(node);
            }
            else{
                // cout<<grp[itsComponent].size()<<" ";
                if(grp[itsComponent].empty()) ans.push_back(-1);
                else if( grp[itsComponent].find( node ) != grp[itsComponent].end() ) ans.push_back(node);
                else ans.push_back(*grp[itsComponent].begin());
            }

        }
        return ans;

    }
};