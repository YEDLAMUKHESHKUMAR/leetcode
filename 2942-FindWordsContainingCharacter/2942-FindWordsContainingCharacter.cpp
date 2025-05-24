// Last updated: 5/24/2025, 10:25:28 AM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& s, char x) {
        int n = s.size();
        vector<int> ans;
        for(int i = 0; i < n ;i++){
            for(auto  ch : s[i]){
                if(ch == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};