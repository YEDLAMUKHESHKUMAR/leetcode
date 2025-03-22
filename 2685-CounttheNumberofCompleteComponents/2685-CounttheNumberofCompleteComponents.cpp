// Last updated: 3/22/2025, 5:52:35 PM
class Solution {
public:
    class DisjointUnion{
        public:
        vector<int> size;
        vector<int> parent;
        DisjointUnion(int n){
            size.resize(n);
            parent.resize(n);
            for(int i = 0; i < n;i++){
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
            else {
                parent[px] = py;
                size[py] += size[px];
            }
        }
        int vertices(int x){
            int px = findParent(x);
            // cout<<endl;
            return size[px];
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointUnion un(n);
        vector<int> edjCount(n,-1);
        for(auto edj : edges){
            un.Union(edj[0], edj[1]);
        }
        for(auto edj : edges){
            int u = edj[0], v = edj[1];
            int px = un.findParent(u);
            if(edjCount[px] == -1) edjCount[px] = 1;
            else edjCount[px]++; 
        }
        int connectedComponents = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n ;i++){
            int v = un.vertices(i);
            if(v == 1){
                connectedComponents++;
            }
            else if(edjCount[i] != -1 ){
                
                int totalEdges = edjCount[i];
                if( (v * ( v - 1 ) / 2)  == totalEdges){
                    connectedComponents++;
                }
                vis[un.findParent(i)] = 1;
                
            }
            
        }
        for(auto i : edjCount) cout<<i<<" ";
        return connectedComponents;
    }
};