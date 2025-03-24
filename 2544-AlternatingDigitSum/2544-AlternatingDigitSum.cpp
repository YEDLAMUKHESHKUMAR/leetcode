// Last updated: 3/24/2025, 6:42:37 PM
#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // 1 2 2 4 5
        ll n = nums.size();
        ll ans = 1;
        unordered_map<ll,ll> mp;
        unordered_map<ll,ll> vis;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n;i++){
            mp[nums[i]]++;
        } 
        if(mp[1] % 2 == 0 && mp[1] > 0) mp[1]--;
        ans = max(1LL, mp[1]);
        vis[1] = 1;
        for(int i = 0; i < n ;i++){
            if(vis[nums[i]] == 0){
                ll element = nums[i];
                ll count = mp[nums[i]];
                ll len = 0;
                vis[element] = 1;
                while(count >= 2){
                    len+=2;
                    element = element * element;
                    
                    if(mp[element] == 1){
                        len++;
                    }
                    else if(mp[element] == 0){
                        if(len > 2) len--;
                        else len = 0;
                    }
                    count = mp[element];
                    vis[element] = 1;
                }
                ans = max(ans, len);
            }
            
        }
        return ans;



        

    }
};