void solve(int index,int k,int target,vector<int> &store, vector<vector<int>> &ans){
    if(k==store.size()){
        if(target==0){
            ans.push_back(store);           // :)
        }
        return;
    }
    for(int i=index;i<10;i++){
        if(i>target) break;
        store.push_back(i);
        solve(i+1,k,target-i,store,ans);
        store.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> store;
        if(n>45) return ans;
        solve(1,k,n,store,ans);
        return ans;
        
    }
};