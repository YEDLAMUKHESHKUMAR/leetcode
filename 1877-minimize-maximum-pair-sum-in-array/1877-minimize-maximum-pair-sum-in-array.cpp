class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minMax = INT_MIN;
        for(int i=0;i<n/2;i++){
            minMax = max(minMax , nums[n-i-1] + nums[i]);
        }
        return minMax;
    }
};