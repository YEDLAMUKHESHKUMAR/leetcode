class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int,vector<int>> mp;
        int m = edges.size();
        for(int i = 0;i<m;i++){
            mp[edges[i][0]].push_back(edges[i][1]);  
            mp[edges[i][1]].push_back(edges[i][0]);  
        }
        vector<int> visited(n); // it should be based on number of vertices not based on size of the edges
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int el = q.front();
            int size = mp[el].size();
            q.pop();
            visited[el]++;
            for(int i  = 0;i<size;i++){
                if(visited[mp[el][i]] == 0){
                    q.push(mp[el][i]);
                    visited[mp[el][i]]++; // what if you are storing it multiple times...
                }
            if(mp[el][i] == destination) return true;
            }
            if(el == destination) return true;
        }
        return false;

    }
};