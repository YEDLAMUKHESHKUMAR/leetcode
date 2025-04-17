// Last updated: 4/17/2025, 9:55:25 AM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n ;i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] == nums[j] && (i * j ) % k == 0) ans++;
            }
        }
        return ans;
    }
};