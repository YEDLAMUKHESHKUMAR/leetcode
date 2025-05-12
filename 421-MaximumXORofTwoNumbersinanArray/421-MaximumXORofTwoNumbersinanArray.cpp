// Last updated: 5/12/2025, 11:37:44 AM
struct Node{
    Node* links[2];
    bool containsBit(int bit){
        return links[bit] != NULL;
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* nextRef(int bit){
        return links[bit];
    }
};

class Trie{
    private : 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int n){
            Node* node = root;
            for(int pos = 31 ; pos>=0 ;pos--){
                int bit = ( n >> pos ) & 1;
                if(!node->containsBit(bit)){
                    node->put(bit, new Node());
                }
                node = node->nextRef(bit);
            }
        }
        int getMaxXor(int x){
            Node* node = root;
            long long ans = 0;
            for(int pos = 31 ; pos >= 0; pos--){
                int bit = (x >> pos) & 1;
                int oppositeBit = (bit ^ 1);
                // cout<<oppositeBit<<endl;
                if(node->containsBit(oppositeBit)){
                    ans += (long long)(pow(2, pos)); 
                    node = node->nextRef(oppositeBit);
                }
                else{
                    node = node->nextRef(bit);
                }
            }
            return ans;
        }
};

class Solution {
public:
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();    
        Trie trie;
        for(int i = 0; i < n ;i++){
            trie.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            ans = max(ans, trie.getMaxXor(nums[i]));
        }
        return ans;
    }
};