class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());  // :) just try all possible ways
        int n = nums.size();
        if(n <= 3) return 0;
        int f,s,t;
        int minAns = INT_MAX;
        minAns = min(minAns,nums[n-1] - nums[3]);  // take first 3 last 0  (3,0)
        minAns = min(minAns,nums[n-2] - nums[2]); // 2,1
        minAns = min(minAns,nums[n-3] - nums[1]); // 1,2 
        minAns = min(minAns,nums[n-4] - nums[0]); // 0,3
        return minAns;

        

    }
};