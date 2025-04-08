// Last updated: 4/8/2025, 9:17:54 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int i = 0,j = 0;
        for(i = 0; i<n;i++){
            mp[nums[i]]++;
            while(j <= i && mp[nums[i]] > 1){
                mp[nums[j]]--;
                j++;
            }
        }
        int mul = j / 3;
        if(j % 3 != 0) mul++;
        return mul;
    }
};