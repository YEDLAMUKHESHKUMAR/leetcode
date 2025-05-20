// Last updated: 5/20/2025, 4:15:56 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> lineSweep(n + 1, 0);
        for(int i = 0; i < m ;i++){
            lineSweep[ queries[i][0] ]++;
            lineSweep[ queries[i][1] + 1 ]--;
        }
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += lineSweep[i];
            if(nums[i] > sum) return false;
        }
        return true;

    }
};