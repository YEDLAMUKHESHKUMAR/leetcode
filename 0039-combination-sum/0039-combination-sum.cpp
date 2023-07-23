void solve(vector<int> &nums,int target,int i,vector<int> &store,vector<vector<int>> &ans){
    if(i==nums.size()){
        if(target==0){
            ans.push_back(store);       // striver's recursion
        }
        return;
    }
    if(nums[i]<=target){
        store.push_back(nums[i]);
        solve(nums,target-nums[i],i,store,ans);
        store.pop_back();
    }
    solve(nums,target,i+1,store,ans);
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        solve(candidates,target,0,store,ans);
        return ans;
    }
};