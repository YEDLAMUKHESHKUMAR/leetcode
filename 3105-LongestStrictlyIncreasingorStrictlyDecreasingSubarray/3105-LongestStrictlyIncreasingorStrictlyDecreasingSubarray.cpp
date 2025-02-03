class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, c = 1;
        for(int i = 1 ; i< n;i++){
            if(nums[i] > nums[i-1]) c++;
            else{
                maxi = max(maxi, c);
                c = 1;
            }
        }
        maxi = max(maxi,c);
        c = 1;
        for(int i = 1; i<n;i++){
            if(nums[i] < nums[i-1]) c++;
            else{
                maxi = max(maxi, c);
                c = 1;
            }
        }
        maxi = max(maxi, c);
        return maxi;
    }
};