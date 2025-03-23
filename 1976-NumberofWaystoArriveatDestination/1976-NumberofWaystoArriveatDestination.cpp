// Last updated: 3/23/2025, 11:01:10 AM
class Solution {
public:
    int countPaths(int  n, vector<vector<int>>& roads) {
        // notes
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

        
        vector<long long> ways(n);
        vector<long long> dist(n,LLONG_MAX);
        priority_queue< pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>> > pq;
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0}); // {dist,node};
        while(!pq.empty()){
            long long node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            for(auto adj:graph[node]){
                long long nextNode = adj.first;
                long long newTime = time + adj.second;
                if(newTime < dist[nextNode]){
                    dist[nextNode] = newTime;
                    ways[nextNode] = 0;
                    ways[nextNode]  = ( ways[nextNode] +  ways[node] ) % mod ;
                    pq.push({newTime,nextNode});
                }
                else if(newTime == dist[nextNode]){
                    ways[nextNode]  = ( ways[nextNode] +  ways[node] ) % mod ;
                }
            }
        } 
        return ways[n-1] % mod ;

    }
};