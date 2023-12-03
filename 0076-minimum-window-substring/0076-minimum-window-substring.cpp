class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n2=t.size(),n1 = s.size();     // :) T_T  // notes
        for(int i=0;i<n2;i++){
            mp1[t[i]]++;
        }
        int i=0,j=0;
        int size = 0 , ans = INT_MAX;
        string res;
        // string str;
        for(int j=0;j<n1;j++){
            // res = s[j] + res;
            char c = s[j];
            if(mp1.find(c)!=mp1.end()){
                mp2[c]++;
                if(mp2[c] <= mp1[c]){
                    size++;
                }
            }
            if(size >= n2){
                while(mp1.find(s[i]) == mp1.end() || mp2[s[i]] > mp1[s[i]]){
                    mp2[s[i]]--;
                    // if(mp2[s[i]] < mp1[s[i]]){
                        // size--;
                    i++;
                }
                if(ans > j-i+1){
                    ans = j-i+1;
                    res = s.substr(i,ans);
                }
            }
            
        }

        return res;

    }
};