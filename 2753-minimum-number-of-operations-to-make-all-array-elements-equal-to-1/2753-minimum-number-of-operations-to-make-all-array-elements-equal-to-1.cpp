class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int gcd = nums[0];
        int ones = 0;
        if(nums[0] == 1) ones++;
        for(int i = 1; i < n ;i++){
            gcd = __gcd(gcd, nums[i]);
            if(nums[i] == 1) ones++;
        }
        if(gcd != 1) return -1;
        if(ones > 0 ){
            return n - ones;
        }
        int small = n;
        for(int i = 0; i < n ;i++){
            int curr = nums[i];
            for(int j = i + 1;j < n; j++){
                curr = __gcd(curr, nums[j]);
                if(curr == 1){
                    small = min(small, j - i + 1);
                }
            }
        }
        return n - 1 + (small - 1);
    }
};