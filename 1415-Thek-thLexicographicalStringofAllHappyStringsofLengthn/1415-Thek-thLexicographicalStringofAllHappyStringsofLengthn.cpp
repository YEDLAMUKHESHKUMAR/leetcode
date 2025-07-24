// Last updated: 7/24/2025, 3:32:39 PM
class Solution {
public:
    vector<string> chars = {"a", "b", "c"};
    void solve( int prev, int n, int& k ,string curr, string& ans){
        if(curr.size() == n) {
            k--;

            if(k == 0){
                ans = curr;
            }
            return;
        }
        // cout<<curr<<endl;

        for(int ind = 0 ; ind < 3; ind++){
            if(ind != prev){
                solve(ind, n, k, curr + chars[ind], ans );
            }
        }

    }
    string getHappyString(int n, int k) {
        string ans = "";
        solve( -1, n, k, "", ans);
        return ans;
    }
};