class Graph {
public:
    vector<vector<pair<int,int>>> adjList;
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto& e:edges){
            adjList[e[0]].push_back(make_pair(e[1],e[2]));
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back(make_pair(edge[1],edge[2]));
    }
     //            Dijkstra's Algorithm 
    int shortestPath(int node1, int node2) {
        int n = adjList.size();
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> costForNode(n,INT_MAX) ; // initializing all costs to infinity 
        costForNode[node1]= 0 ; // assume cost of initial node is 0 
        pq.push({0,node1});
        while(!pq.empty()){
            int currCost = pq.top()[0];
            int currNode = pq.top()[1];
            pq.pop();
            if(currCost > costForNode[currNode]) continue;  // it is larger, no need to update cost
            if(currNode == node2) return currCost; // if you reached given node return total cost
            for(auto& neighbour : adjList[currNode]){ // traverse every neighbour of currNode
                int neighbourNode = neighbour.first;
                int cost = neighbour.second;
                int newCost = currCost + cost ;
                if(newCost < costForNode[neighbourNode]){  // if a-->b cost is lesser than previous 
                    costForNode[neighbourNode] = newCost ;  // update the cost with newCost ;
                    pq.push({newCost,neighbourNode});
                }
            }

        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */