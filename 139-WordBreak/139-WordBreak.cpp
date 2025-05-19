// Last updated: 5/19/2025, 11:24:47 AM
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* nextRef(char ch){
        return links[ch - 'a'];
    }
    void wordEnded(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }

};

class Trie{
    private : 
    Node* root ;
    public : 
    Trie(){
        root = new Node();
    }
    void insert(string& word){
        Node* node = root;
        for(int i = 0 ;i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->nextRef(word[i]);
        }
        node->wordEnded();
    }

    void getBreaks(int st, string& s, vector<int> &breaks){
        Node* node = root;
        for(int i = st; i < s.size(); i++){
            if(!node->containsKey( s[i] ) ){
                return;
            }
            node = node->nextRef(s[i]);
            if(node->isEnd()){
                breaks.push_back(i + 1);
            }
        }
    }


};

bool dfs(int i, string& s, Trie& trie, unordered_map<int,bool> &dp){
    if(i == s.size()) return true;
    if(dp.find(i) != dp.end()) return dp[i];

    vector<int> breaks;
    trie.getBreaks( i , s, breaks );
    for(auto br : breaks){
        if(dfs(br, s, trie, dp)){
            return dp[i] = true;
        }
    }
    return dp[i] = false;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i = 0; i<wordDict.size(); i++){
            trie.insert(wordDict[i]);
        }
        unordered_map<int,bool> dp;
        return dfs(0, s, trie, dp);
    }
};