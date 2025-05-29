// Last updated: 5/30/2025, 12:35:31 AM
class Solution {
public:
    void buildGraph(vector<vector<int>>& edges, int n, vector<vector<int>> &g){
        for(auto i : edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
    }
    void evens(int node, vector<vector<int>>& g, unordered_map<int,int> &mp){
        queue<pair<int,int>> q;
        q.push({node, -1});
        int level = 1;
        mp[node]++;
        while(!q.empty()){
            int qs = q.size();
            for(int i = 0 ; i < qs;i++){
                int currNode = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto adjNode : g[currNode]){
                    if(parent != adjNode){
                        if(level % 2 == 0){
                            mp[adjNode]++;
                        }
                        q.push({adjNode, currNode});
                    }
                }
            }
            level++;
        }

    }
    int odds(int node, int m, vector<vector<int>> &g){
        queue<pair<int,int>> q;
        q.push({node, -1});
        int level = 1, ans = 0;
        while(!q.empty()){
            int qs = q.size();
            for(int i = 0 ; i < qs;i++){
                int currNode = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto adjNode : g[currNode]){
                    if(parent != adjNode){
                        if(level % 2 == 1) ans++;
                        q.push({adjNode, currNode});
                    }
                }
            }
            level++;
        }
        return max(ans, m - ans);
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = 1 + edges1.size();
        int m = 1 + edges2.size();

        vector<vector<int>> g1(n);
        vector<vector<int>> g2(m);

        // buildGraph(edges1,n, g1);
        // buildGraph(edges2, m,g2);
        for(auto i : edges1){
            g1[i[0]].push_back(i[1]);
            g1[i[1]].push_back(i[0]);
        }

        for(auto i : edges2){
            g2[i[0]].push_back(i[1]);
            g2[i[1]].push_back(i[0]);
        }
        unordered_map<int,int> mp;

        evens(0,g1, mp);
        int e1 = (int)mp.size();
        int rem = n - (int)mp.size();

        int maxAns = odds(0,m, g2);

        vector<int> ans(n, 0);
        for(int i = 0; i < n ;i++){
            int maxi = rem;
            if(mp.find(i) != mp.end()) maxi = e1;
            maxi += maxAns;
            ans[i] = maxi;
        }
        return ans;



        


    }
};