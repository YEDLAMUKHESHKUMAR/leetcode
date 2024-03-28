class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int j = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(j<n && mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        
    return ans;
    }
};