class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // 1 2 3 1 4 5 
        // 1 2 3 1 2 3
        // 3 2 1 3 2 1
        int n = nums.size();
        vector<int> inc(n, 0);
        vector<int> dec(n, 0);
        inc[0] = 1;
        dec[n - 1] = 1;
        int c = 1;
        for(int i = 1; i < n ;i++){
            if(nums[i] >= nums[i - 1]){
                c++;
            }
            else c = 1;
            inc[i] = c;
        }
   
        c = 1;
        for(int i = n - 2; i >= 0 ; i--){
            if(nums[i] <= nums[i + 1]){
                c++;
            }
            else c = 1;
            dec[i] = c;
           
        }
        
        int ans = 0;
        if(n == 1) return 1;
        for(int i = 0; i < n ; i++){
            if(i > 0 && i < n - 1){
                if(nums[i - 1] <= nums[i + 1]){
                    ans = max(ans, 1 + inc[i - 1] + dec[i + 1]);
                }
            }
            
            if(i < n - 1 ){
                ans = max(ans, 1 + dec[i + 1] );
            }
            if(i > 0){
                ans = max(ans, 1 + inc[i - 1]);
            }
            
        }
        
        return min(ans, n);
    }
};