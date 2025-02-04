class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0], maxi = sum;
        for(int i = 1; i<n;i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            }
            else{
                maxi = max(maxi, sum);
                sum = nums[i];
            }
            // cout<<sum<<endl;
        }
        maxi = max(maxi, sum);
        return maxi;
    }
};