class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // use dp, LIS ... edit : TLE 
        // newApproach : just fix middle element means, find if there exist left min and rightMax for any element.
        int n = nums.size();
        vector<bool> leftMin(n);
        leftMin[0] = false;
        int mini = nums[0];
        for(int i = 1; i<n;i++){
            if(nums[i] > mini){
                leftMin[i] = true;
            }
            mini = min(mini, nums[i]);
        }  
        int maxi = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i] < maxi && leftMin[i] == true) return true;
            maxi = max(maxi, nums[i]);
        }
        return false;
        
    }
};