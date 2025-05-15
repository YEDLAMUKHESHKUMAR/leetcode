// Last updated: 5/15/2025, 7:01:26 PM
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
                // cout<<oppositeBit<<endl;
                if(node->containsBit(!bit)){
                    ans += (long long)(pow(2, pos)); 
                    node = node->nextRef(!bit);
                }
                else{
                    node = node->nextRef(bit);
                }
            }
            return ans;
        }
};


class Solution {
    static bool cmp( const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // 011 101
        int n = nums.size();
        Trie trie;
        sort(nums.begin(), nums.end());

        int q = queries.size();
        // sort(queries.begin(), queries.end() , [](const vector<int> &a, vector<int> &b){
        //     return a[1] < b[1];
        // });
        vector<pair<int, pair<int,int>>> pair;
        int ind = 0;
        for(auto it: queries) {
            pair.push_back({it[1],{it[0], ind++}}); 
        }
        sort(pair.begin(), pair.end());
        vector<int> ans(q);
        int j = 0;
        for(auto i : pair){
            int m = i.first ;
            int x = i.second.first;
            
            while(j < n && nums[j] <= m){
                trie.insert(nums[j]);
                j++;
            }
            if(j != 0) ans[i.second.second] = trie.getMaxXor(x);
            else ans[i.second.second] = -1;
        }
        return ans;
    }
};