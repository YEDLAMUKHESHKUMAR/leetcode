// Last updated: 7/28/2025, 8:30:30 PM
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int m = (1 << n);
        int OR = 0, ans = 0;
        for(int i = 0 ; i < n ; i++) OR |= nums[i];
        for(int i = 0 ; i < m ; i++){
            int temp = 0;
            for(int pos = 0 ; pos < 32 ; pos++){
                if( ( (i >> pos) & 1 ) ){
                    temp |= nums[pos];
                }
            }
            if(OR == temp) ans++;
        }
        return ans;
    }
};