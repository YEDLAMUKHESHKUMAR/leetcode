class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> deltas(n); // notes
        for (int i = 0; i < n; i++) {
            deltas[i] = (nums[i] ^ k) - nums[i];      // afterXor - beforeXor 
        }
        sort(deltas.rbegin(), deltas.rend()); // reverse sort .... 

        long long res = 0;
        for (int num : nums) {
            res += num;            
        }

        for (int startInd = 0; startInd < n - 1; startInd += 2) {
            long long changingDelta = deltas[startInd] + deltas[startInd + 1]; 
            if (changingDelta > 0) {
                res += changingDelta;
            } else {
                break;
            }
        }

        return res;
    }
};