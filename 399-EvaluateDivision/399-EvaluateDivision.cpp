// Last updated: 6/24/2025, 9:25:42 PM
class Solution {
public:
    double solve(string& u, string& v,unordered_map<string, vector<pair<string,double>>>& graph, unordered_map<string,bool>& vis ){
        if(u == v){
            return 1.0;
        }
        double ans = -1.0;
        vis[u] = true;
        for(auto uu : graph[u]){
            if(vis.find(uu.first) != vis.end()) continue;
            ans = max(ans, uu.second * solve(uu.first, v, graph, vis));
        }
        return ans;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& q) {
        unordered_map<string, vector<pair<string,double>>> graph;
        for(int i = 0; i < values.size() ; i++){
            double rev = 1.0 / values[i];
            string u = equations[i][0];
            string v = equations[i][1];
            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, rev});
        }
        int qs = q.size();
        vector<double> ans;
        for(int i = 0; i < qs;i++){
            unordered_map<string, bool> vis;
            if(graph.find(q[i][0]) == graph.end() || graph.find(q[i][1]) == graph.end()){
                ans.push_back(-1.0);
                continue;
            }
            if(q[i][0] == q[i][1]){
                ans.push_back(1.0);
                continue;
            }
            double res = solve(q[i][0], q[i][1], graph, vis);
            if(res < 0) ans.push_back(-1.0);
            else ans.push_back(res);
        }
        return ans;
    }
};