class Solution {
    unordered_map<string,int> mp;
    vector<vector<string>> ans; 
    string begin ;
private:
    void dfs(string word,vector<string> &seq){
        if(word == begin){
            // reverse(seq.begin(),seq.end()); 
            ans.push_back(seq);
            // reverse(seq.begin(),seq.end()); // this is backtracking....if we just reverse it 1 time, while doing pop_back() we will remove the wrong guy
        }
        int steps = mp[word];
        int sz = word.size();
        for(int i = 0;i<sz;i++){
                char temp = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i] = c;
                    if(mp.find(word) != mp.end() && mp[word] + 1 == steps) { // if the word lies in prev level...then only take it
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i] = temp;
            }
        
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // notes
        queue<string> q;
        begin = beginWord;
        q.push(beginWord);
        mp[beginWord] = 1 ;

        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        int sz = beginWord.size();      // notes
        while(!q.empty()){
            string s = q.front();
            int steps = mp[s];
            q.pop();
            if(s == endWord) break;
            for(int i = 0;i<sz;i++){
                char temp = s[i];
                for(char c = 'a';c<='z';c++){
                    s[i] = c;
                    if(st.count(s)){
                        mp[s] = steps + 1 ;
                        st.erase(s);
                        q.push(s);
                    }

                }
                s[i] = temp;
            }
        }
        if(mp.find(endWord) != mp.end()){ // if map doesn't contain the endWord....simply return empty vector
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        for(int i = 0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;

    }
};