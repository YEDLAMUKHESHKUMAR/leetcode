class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+10);
        vector<vector<int>> ans ; 
        for(int i=0;i<n;i++){
            if(ans.size()<=count[nums[i]]){
                ans.push_back({});
            }
            ans[count[nums[i]]++].push_back(nums[i]);
        }
        return ans;
    }
};