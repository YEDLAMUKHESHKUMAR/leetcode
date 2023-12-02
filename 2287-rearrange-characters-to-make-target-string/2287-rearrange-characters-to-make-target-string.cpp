class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<target.size();i++){
            mp2[target[i]]++;
        }
        int minCopies = mp1[target[0]];
        for(auto i:mp2){
            int tc = i.second;
            int sc = mp1[i.first];
            if( tc > sc) return 0;
            // if(tc*minCopies > sc){
                minCopies = min(minCopies,sc / tc) ;
            // }
            
        }
        return minCopies;

    }
};