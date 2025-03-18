class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(32, 0);
        int j = 0, ans = 0;
        for(int i = 0; i < n;i++){
            bool StreakGone = false;
            for(int pos = 0; pos < 32 ;pos++){
                if( ( nums[i] >> pos) & 1 ){
                    mp[pos]++;
                }
                if(mp[pos] > 1) StreakGone = true;
            }
            while(j <= i && StreakGone){
                bool isItOk = true;
                for(int pos = 0; pos < 32 ;pos++){
                    if( ( nums[j] >> pos) & 1 ){
                        mp[pos]--;
                    }
                    if(mp[pos] > 1 ) isItOk = false;
                }
                if(isItOk) StreakGone = false;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans; 

    }
};