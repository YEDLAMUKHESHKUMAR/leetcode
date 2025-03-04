class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incomingEdges(n, 0); // :)
        for(auto edj : edges){
            incomingEdges[edj[1]]++;
        }
        vector<int> ans;
        for(int i = 0; i<n;i++){
            if(incomingEdges[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};