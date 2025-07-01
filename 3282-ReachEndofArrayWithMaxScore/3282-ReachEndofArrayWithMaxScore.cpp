// Last updated: 7/1/2025, 9:20:44 PM
#define ll long long
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0, prevIndex = 0;
        for(int i = 1; i < n ;i++){
            if(nums[i] > nums[prevIndex]){
                ans += (( i - prevIndex )* nums[prevIndex]);
                prevIndex = i;
            }
        } 
        if(prevIndex != n - 1){
            ans += (n - 1 - prevIndex) * nums[prevIndex];
        }
        return ans;
    }
};