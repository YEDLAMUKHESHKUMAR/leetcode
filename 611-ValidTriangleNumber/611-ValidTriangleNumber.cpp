// Last updated: 7/2/2025, 11:27:56 PM
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // n^2 :)
        int ans = 0;
        for(int i = 0; i < n ;i++){
            int  k = n - 1;
            for(int j = n - 2 ; j > i ; j-- ){ 
                while( j < k && nums[i] + nums[j] <= nums[k] ){
                    k--;
                }
                ans += ( k - j );
                // 4 5 6 8 9 10 11 12
            }
        }
        return ans;
    }
};