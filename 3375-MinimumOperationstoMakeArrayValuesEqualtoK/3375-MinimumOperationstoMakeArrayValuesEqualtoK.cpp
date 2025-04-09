// Last updated: 4/9/2025, 2:13:21 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        unordered_map<int, int> mp;
        for(int i = 0; i < n;i++) {
            mini = min(mini , nums[i]);
            mp[nums[i]]++;
        }
        if(mini < k) return -1;
        if(mp.find(k) != mp.end()) return mp.size() - 1;
        return mp.size();
    }
};