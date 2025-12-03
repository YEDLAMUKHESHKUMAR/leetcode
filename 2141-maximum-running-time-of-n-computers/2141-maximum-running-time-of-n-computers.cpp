#define ll long long
class Solution {
public:
    ll isPossible(ll mid, vector<int>& nums, ll n){
        ll m = nums.size(); 
        ll sum = 0;
        // notes
        for(int i = 0; i < m ; i++){
            if(nums[i] >= mid){
                n--;
            }
            else{
                sum += nums[i];
            }
        }
        if(n * mid > sum) return false;
        return true;
        
    }
    long long maxRunTime(int n, vector<int>& nums) {
        ll m = nums.size();
        sort(nums.begin(), nums.end());
        ll low = 0, high = 1e14;
        ll ans = 0;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(isPossible(mid, nums, n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};