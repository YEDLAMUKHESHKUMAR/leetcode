// Last updated: 6/7/2025, 9:42:29 AM
class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> mp(26);
        vector<int> finalIndices;
        int n = s.size();
        for(int i = 0; i < n ;i++){
            if(s[i] == '*'){
                for(int pos = 0; pos < 26 ;pos++){
                    if(!mp[pos].empty()){
                        mp[pos].pop_back();
                        break;
                    }
                }
            }
            else{
                mp[s[i] - 'a'].push_back(i);
            }
        }
        for(int i = 0; i < 26 ; i++){
            for(auto j : mp[i]){
                finalIndices.push_back(j);
            }
        }
        sort(finalIndices.begin(), finalIndices.end());
        string ans = "";
        for(auto &i : finalIndices){
            ans += s[i];
        }
        return ans;
    }
};