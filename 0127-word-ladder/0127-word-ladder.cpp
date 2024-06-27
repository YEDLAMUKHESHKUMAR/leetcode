class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // notes
        int n = beginWord.size();
        unordered_map<string,int> mp;
        for(int i = 0;i<wordList.size();i++){
            mp[wordList[i]]++;
        }
        if(mp.find(endWord) == mp.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            for(int i = 0 ;i < n ;i++){
                string temp = word;
                for(int j = 0;j<26;j++){
                    temp[i] = char( j + 'a');
                    // cout<<temp<<endl;
                    if(temp == endWord) return level + 2 ;
                    if(mp.find(temp) != mp.end()){
                        // return 32;
                        q.push({temp,level + 1 });
                        mp.erase(temp);
                    }
                }
            }
            
        }
        return 0;

    }
};