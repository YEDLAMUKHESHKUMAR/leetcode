class Solution {
public:
    void solve(vector<int> &nums,vector<int> &mp,vector<int> &temp,vector<vector<int>> &ans){
        int n=nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[i]==0){
                temp.push_back(nums[i]);
                mp[i]=1;
                solve(nums,mp,temp,ans);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> mp(n,0);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,mp,temp,ans);
        return ans;
    }
};