class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n ;i++) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());
        long long bigSum = 0, smallSum = 0;
        long long j = 0;
        for(int i = 1; i < n ;i+=2){
            smallSum += (1LL * nums[j] * nums[j]);
            j++;
        }
        for(int i = 0; i < n; i+= 2){
            bigSum += (1LL * nums[j] * nums[j]);
            j++;
        }
        return bigSum - smallSum;

    }
};