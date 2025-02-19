class Solution {
public:
    void solve(int prev, string temp, int n, vector<string> &ans){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < 3; i++){
            char ch = char('a' + i);
            if(prev != i){
                solve(i, temp + ch, n, ans);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        solve(-1, "", n, ans );
        sort(ans.begin(), ans.end());
        for(auto i : ans) cout<<i<<endl;
        if(ans.size() < k) return "";
        return ans[k - 1];
    }
};