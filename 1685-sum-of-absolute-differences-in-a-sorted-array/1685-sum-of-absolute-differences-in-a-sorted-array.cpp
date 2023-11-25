class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            prefix[i] = sum;
            sum+=nums[i];
        }
        sum = 0;
        for(int i=n-1;i>=0;i--){
            int  j = n - i - 1 ;
            int absoluteDiff = abs(prefix[i] - nums[i] * i ) + abs(sum - nums[i] * j);
            sum+=nums[i];
            nums[i] = absoluteDiff;
        }
        return nums;
    }
};