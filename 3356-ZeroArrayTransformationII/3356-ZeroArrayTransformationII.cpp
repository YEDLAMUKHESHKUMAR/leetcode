class Solution {
public:
    int solve(vector<int> &nums, vector<vector<int>> &q, int m){
        int n = nums.size(), sum = 0;
        vector<int> lineSweep(n + 2 , 0);
        for(int i = 0; i <= m ;i++){
            int fir = q[i][0];
            int second = q[i][1];
            int val = q[i][2];
            lineSweep[fir] += val;
            lineSweep[second + 1] -= val;
        }
        // cout<<
        for(int i = 0; i < n; i++){
            sum += lineSweep[i];
            if(nums[i] > sum){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
       
        int n = nums.size();
        int qs = q.size();
        int low = 0, high = qs - 1 , ans = -1;
        int zeroes = 0;
        for(int i = 0; i < n ;i++){
            if(nums[i] == 0) zeroes++;
        }
        if(zeroes == n) return 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(nums, q, mid) == true){
                ans = mid + 1;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;

    }
};