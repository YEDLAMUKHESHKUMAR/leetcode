class Solution {
public:
    void solve(int ind,vector<int> &nums,vector<int> &dp,vector<vector<int>> &ans){
        ans.push_back(dp);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;   // 200th problem :)
            dp.push_back(nums[i]);
            solve(i+1,nums,dp,ans);
            dp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> dp;
        sort(nums.begin(),nums.end());
        solve(0,nums,dp,ans);
        return ans;
    }
};