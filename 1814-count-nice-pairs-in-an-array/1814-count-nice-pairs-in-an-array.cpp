class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int mod = 1e9 + 7 ;
        int n = nums.size();        // :)
        long long nicePairs = 0;
        for(int i=0;i<n;i++){
            int t = nums[i];
            int rev = 0 , rem;
            while(t!=0){
                rem = t % 10;
                rev = rev * 10 + rem;
                t /= 10;
            }
            long long difference = nums[i] - rev;
            if(mp[difference] > 0){
                nicePairs += mp[difference] % mod;
            }
            mp[difference]++;
        }
        return nicePairs % mod;
    }

};