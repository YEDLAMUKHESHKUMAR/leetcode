// Last updated: 5/30/2025, 1:10:53 PM
class Solution {
public:
    void bfs(int node, vector<int> &edges, vector<int>& dist){
        queue<pair<int,int>> q;
        q.push({node, 0});
        dist[node] = 0;
        while(!q.empty()){
            int currNode = q.front().first;
            int currDist = q.front().second;
            cout<<currDist<<" ";
            q.pop();
            int adjNode = edges[currNode];
            if(adjNode == -1 ) continue;
            if(currDist + 1 < dist[adjNode]){
                dist[adjNode] = currDist + 1;
                q.push({adjNode, currDist + 1});
            }

        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> minD1(n, INT_MAX);
        vector<int> minD2(n, INT_MAX);

        bfs(node1, edges, minD1);
        bfs(node2, edges, minD2);

        int maxi = INT_MAX, minDistAns = -1;
        for(int i = 0; i < n ;i++){
            int both = max(minD1[i], minD2[i]);
            if(both < maxi){
                maxi = both;
                minDistAns = i;
            }
        }
        return minDistAns;


    }
};