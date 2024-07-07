class Solution {
public:
    bool dfs(int i,int c,vector<vector<int>> &graph,int col[]){
        col[i] = c;
        for(auto v:graph[i]){
            if(col[v] == -1){
                if(dfs(v, !c , graph,col) == false) return false;
            } 
            else if(c == col[v]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {     // notes
        int n = graph.size();
        int col[n];
        for(int i = 0 ;i<n;i++){
            col[i] = -1 ;
        }
        for(int i = 0;i<n;i++){
            if(col[i]  == -1 ){
                if(dfs(i,0,graph,col) == false) return false;
            }
        }
        return true;
    }
};