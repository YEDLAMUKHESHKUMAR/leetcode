class Solution {
public:
/*
         0 - 1 , 2
         1 - 4 , 5
         2 - 3 , 6
         3 
         4 
         5 
         6 
        
        */


    vector<int> solve(int node, int n, vector<int> graph[], string &labels, int parent, vector<int> &ans){
        vector<int> map(26,0);

        for(auto adj : graph[node]){
            if(adj != parent ){
                vector<int> vec(26,0);
                vec = solve(adj, n, graph, labels, node, ans);
                for(int i = 0; i < 26 ;i++){
                    map[i] += vec[i];
                }
            }
        }
        map[ labels[node] - 'a' ]++;
        ans[node] = map[ labels[node] - 'a' ];
        return map;



    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> ans(n, 0);
        vector<int> graph[n];
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        solve(0, n, graph, labels, -1, ans);
        return ans;
    }
};