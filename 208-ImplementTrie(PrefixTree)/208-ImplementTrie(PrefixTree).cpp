// Last updated: 5/8/2025, 7:06:21 PM
struct Node{
    Node* links[26];
    bool last = false;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void putKey(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* getNextNode(char ch){
        return links[ch - 'a'];
    }
};

class Trie {
    private:
        Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if( !node->containsKey(word[i]) ){
                node->putKey(word[i], new Node());
            }
            node = node->getNextNode(word[i]);
        }
        node->last = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getNextNode(word[i]);
        }
        if(node->last == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getNextNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */