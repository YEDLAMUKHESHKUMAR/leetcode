void solve(int open,int close,int n,string store,vector<string> &ans){
    if(store.size()==n*2){
        ans.push_back(store);        // :)
        return;
    }
    if(open<n){
        
        solve(open+1,close,n,store+"(",ans);
    }
    if(close<open){
        // store.pop_back();
        // store.push_back(')');
        solve(open,close+1,n,store+")",ans);
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // string store="";
        solve(0,0,n,"",ans);
        return ans;
        
    }
};