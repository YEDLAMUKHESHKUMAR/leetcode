class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int Key,int Val){         // DLL + HASHING 
            key=Key;
            val=Val;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(node* getNode){
        getNode->prev->next = getNode->next;
        getNode->next->prev = getNode->prev;
    }
    void addNode(node* getNode){
        getNode->next = head->next;
        getNode->next->prev = getNode;
        head->next = getNode;
        getNode->prev = head; 
    }
    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            node* getNode = mp[key_];
            int result = getNode->val;
            mp.erase(key_);
            deleteNode(getNode);
            addNode(getNode);
            mp[key_]=head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_)!=mp.end()){
            node* getNode = mp[key_];
            mp.erase(key_);
            deleteNode(getNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key_,value));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */