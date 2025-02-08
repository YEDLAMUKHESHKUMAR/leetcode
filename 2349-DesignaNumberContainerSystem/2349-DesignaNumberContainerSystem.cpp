class NumberContainers {
public: 
    unordered_map<int,int> mp;
    // unordered_map<int, priority_queue<int, vector<int> , greater<int> >> pq; // instead of using this and another set to track overwritten indexes with numbers..
    // set<pair<int,int>> st;
    unordered_map<int, set<int>> st; // we can just use set inside of it...it is same as previous right...
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // same as prev , skip...
        if(mp.find(index) != mp.end()){
            if(mp[index] == number) return;
            int prev = mp[index];

            st[prev].erase(index); // removed..
        }
        mp[index] = number;
        st[number].insert(index);
    }
    
    int find(int number) {
        if(st[number].empty()) return -1;
        auto small = st[number].begin();
        return *small;
        // while(!pq[number].empty() && (st.find({number, pq[number].top()}) != st.end())  ){
        //     st.erase({number,pq[number].top()});
        //     pq[number].pop();
        // }
        // if(pq[number].empty()) return -1;
        // return pq[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */