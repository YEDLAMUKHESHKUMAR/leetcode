class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[2] == b[2] ? a[0] < b[0] : a[2]<b[2] ;
    }
    void solve(int node, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& vis, unordered_map<int,int>& knowsSecret){
        vis[node] = 1;
        knowsSecret[node]++;
        for(auto i : graph[node]){
            if(!vis[i]){
                solve(i, graph, vis, knowsSecret);
            }
        }


        

    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, int> knowsSecret;
        sort(meetings.begin(), meetings.end(), cmp);
        // for(int i = 0; i < meetings.size();i++){
        // }
        // return {meetings[0][2]};
        knowsSecret[0]++;
        knowsSecret[firstPerson]++;
        
        int time = 1;
        int i = 0;
        while(i < meetings.size() ){
            unordered_map<int, vector<int>> graph;
            unordered_map<int, int> vis;
            while(i < meetings.size() && meetings[i][2] <= time){
                graph[meetings[i][0]].push_back(meetings[i][1]);
                graph[meetings[i][1]].push_back(meetings[i][0]);
                i++;
            }
            for(auto j : graph){
                if(!vis[j.first] && knowsSecret.find(j.first) != knowsSecret.end()) {
                    solve(j.first, graph, vis, knowsSecret);
                }
            }
            
            if(i >= meetings.size()) break;
            time = meetings[i][2];
            
        }
        vector<int> ans;
        for(auto i: knowsSecret){
            ans.push_back(i.first);
        }
        sort(ans.begin(), ans.end());
        return ans;


    }
};