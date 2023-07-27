void solve(int index,int target,vector<int> &arr,vector<int> &store,vector<vector<int>> &ans){
    if(target==0){
        ans.push_back(store);
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue;  // striver
        if(arr[i]>target) break;
        store.push_back(arr[i]);
        solve(i+1,target-arr[i],arr,store,ans);
        store.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,store,ans);
        return ans;
    }
};