// Last updated: 6/8/2025, 2:36:46 PM
class Solution {
public:
    void solve(int i, int n, vector<int> &ans){
        if(i > n) return;
        ans.push_back(i);
        for(int j = 0; j < 10; j++){
            solve(i * 10 + j , n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1 ; i<= 9 ;i++){
            solve(i, n, ans);
        }
        return ans;
    }
};