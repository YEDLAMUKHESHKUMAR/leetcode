void solve(int current_num,int k,int n,vector<int> &ds,vector<vector<int>> &ans){
    if(current_num>n){
        if(ds.size()==k){
            ans.push_back(ds);
        }
        return;
    }
    if(ds.size()==k){
        ans.push_back(ds);
        return;
    }
    ds.push_back(current_num);
    solve(current_num+1,k,n,ds,ans);
    ds.pop_back();
    solve(current_num+1,k,n,ds,ans);
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};