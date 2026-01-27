/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/



class Solution {
public:
    void deepCopy(Node* node, Node* clonedNode, unordered_map<int, Node*>& cloned){
        for(auto adj : node->neighbors){
            int currValue = adj->val;
            if(cloned.find(currValue) != cloned.end()){
                clonedNode->neighbors.push_back(cloned[currValue]);
            }
            else{
                Node* newClonedNode = new Node(currValue);
                cloned[currValue] = newClonedNode;
                clonedNode->neighbors.push_back(newClonedNode);
                deepCopy(adj, newClonedNode, cloned);
            }
        }

    }
    Node* cloneGraph(Node* root) {
        if(root == NULL) return NULL;
        unordered_map<int, Node*> cloned;
        Node* node = new Node(1);
        cloned[1] = node; 
        deepCopy(root, node, cloned);
        return node;
    }
};