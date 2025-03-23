// Last updated: 3/23/2025, 11:03:12 AM
#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> graph[n];
        long long mod = 1e9 + 7;
        long long m = roads.size(); // notes
        for(int i =0;i<m;i++){
            long long u = roads[i][0]  ;
            long long v = roads[i][1] ; 
            long long w = roads[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<ll> paths(n , 0);
        priority_queue< pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
        pq.push({0,0});
        paths[0] = 1;
        dist[0] = 0;
        while(!pq.empty()){
            ll time = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto adjNode : graph[node]){
                ll newTime = time + adjNode.second % mod;
                ll adjacent = adjNode.first;
                if(newTime < dist[adjacent]){
                    // if(adjacent == n-1){
                    //     if(newTime < dist[adjacent]){
                    //         paths[adjacent] = 0;
                    //     }
                    //     paths[n-1] = paths[n-1] + 1 % mod;
                    // }
                    dist[adjacent] = newTime ;
                    paths[adjacent] = 0;
                    paths[adjacent] = paths[node]  % mod;
                    pq.push({newTime, adjacent });
                }
                else if(newTime == dist[adjacent]){
                    paths[adjacent] = (paths[adjacent] + paths[node] ) % mod;
                }
            }
        }
        return paths[n-1] % mod;

    }
};