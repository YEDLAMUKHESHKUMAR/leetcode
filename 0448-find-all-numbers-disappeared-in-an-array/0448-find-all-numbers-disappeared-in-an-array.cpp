class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> mp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-1]++;
        }
        vector<int> ans ; 
        for(int i=0;i<mp.size();i++){
            if(mp[i]==0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};