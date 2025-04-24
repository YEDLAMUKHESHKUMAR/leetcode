// Last updated: 4/24/2025, 3:33:38 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> distinct;
        unordered_map<int,int> mp;
        for(int i = 0; i < n ;i++) {
            distinct[nums[i]]++;
        }
        int ans = 0, count = 0, tot = distinct.size(), j = 0;
        for(int i = 0; i < n ;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 1) count++;
            while(j <= i && count == tot){
                ans += (n - i);
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) count--;
                j++;
            }
        }
        return ans;
    }
};