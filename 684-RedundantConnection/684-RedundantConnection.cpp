class Solution {
public:
    class DisjointUnion{
        vector<int> size;
        vector<int> parent;
        public:
        DisjointUnion(int n){
            size.resize(n);
            parent.resize(n);
            for(int i = 0; i<n;i++){
                size[i] = 1;
                parent[i] = i;
            }
        }
        int findParent(int x){
            if(parent[x] == x) return x;
            return parent[x] = findParent(parent[x]);
        }

        void Union(int x, int y){
            int px = findParent(x);
            int py = findParent(y);
            if(px == py) return;

            if(size[px] >= size[py]){
                parent[py] = px;
                size[px] += size[py];
            } 
            else{
                parent[px] = py;
                size[py] += size[px];
            }
        }

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v = edges.size();
        DisjointUnion un(v+1);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int pu = un.findParent(u);
            int pv = un.findParent(v);
            if(pu == pv){
                return {u,v};
            }
            un.Union(u,v); 
        }
        return {};


    }
};