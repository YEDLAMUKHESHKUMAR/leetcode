class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        int m = endWord.size();
        // if(n != m) return 0;
        queue<string> currWords;
        unordered_map<string, int> containsWord;
        unordered_map<string, int> vis;
        for(int i = 0; i < wordList.size(); i++){
            containsWord[wordList[i]]++;
        }
        if(containsWord.find(endWord) == containsWord.end()){
            return 0;
        }
        currWords.push(beginWord);
        int level = 0;
        while(!currWords.empty()){
            level++;
            int size = currWords.size();
            for(int i = 0 ; i < size; i++){
                string word = currWords.front();
                if(word == endWord) return level;
                vis[word]++;

                for(int j = 0; j < word.size(); j++){
                    char tempCurrChar = word[j];
                    for(char ch = 'a' ; ch <= 'z' ; ch++){
                        word[j] = ch;
                        if(vis.find(word) == vis.end() && containsWord.find(word) != containsWord.end()){
                            currWords.push(word);

                        }
                    }
                    word[j] = tempCurrChar;
                }

                currWords.pop();
            }

        }
        return 0;

        
        
    }
};