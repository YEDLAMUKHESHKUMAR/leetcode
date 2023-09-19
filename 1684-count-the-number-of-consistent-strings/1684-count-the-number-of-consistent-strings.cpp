class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        int count=0;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        for(int i=0;i<words.size();i++){
                bool consistent=true;
                for(int j=0;j<words[i].size();j++){
                    if(mp.find(words[i][j])==mp.end()) {
                        consistent=false;
                        break;
                    }
                    
                }
                if(consistent==true) {
                    count++;
                    
                }
            
        }
        return count;
    }
};