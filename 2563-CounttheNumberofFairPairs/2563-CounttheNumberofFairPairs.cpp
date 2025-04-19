// Last updated: 4/19/2025, 2:40:02 PM
class Solution {
public:
    long long getUpperBoundElement(int i, vector<int> &nums, int lower, int upper){
        long long l = i+1,h = nums.size() - 1;
        while(l <= h){
            long long mid = (l + h )/ 2;
            if(nums[i] + nums[mid] >= lower ){
                h = mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
    long long getLowerBoundElement(int i, vector<int> &nums, int lower, int upper){
        long long l = i+1,h = nums.size() - 1;
        while(l <= h){
            long long mid = (l + h )/ 2;
            if(nums[i] + nums[mid] <= upper ){
                l = mid+1;
            }
            else h=mid-1;
        }
        return h;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // 0 1 4 4 5 7  // :)
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i = 0;i<n-1;i++){
            long long l = getUpperBoundElement(i,nums,lower,upper);
            long long r = getLowerBoundElement(i,nums,lower,upper);
            if( l>=n || r < i || ((nums[i] + nums[l] ) > upper) ||  ((nums[i] + nums[r] ) < lower) ) continue;
            ans += (r - l + 1);
        }
        return ans;
    }
};