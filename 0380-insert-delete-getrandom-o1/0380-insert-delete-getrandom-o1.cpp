class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size() - 1 ; 
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end() ) return false;
        int lastElement = v.back() ; 
        mp[lastElement] = mp[val] ; // give val position to lastElement ..
        v[mp[val]] = lastElement ;  // put val at last 
        v.pop_back();               // delete it .. simply we are overriding it and then deleting it
        mp.erase(val);
        return true;

    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */