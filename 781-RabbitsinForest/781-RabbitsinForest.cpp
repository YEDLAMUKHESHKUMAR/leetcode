// Last updated: 4/20/2025, 10:00:06 PM
class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> count;
        int ans = 0;
        for(int i = 0; i < n ;i++){
            if(nums[i] == 0) {
                ans++;
                continue;
            }
            count[nums[i]]++;
            if( mp[nums[i]] == count[nums[i]] ){
                ans += mp[nums[i]];
                mp.erase(nums[i]);
                count.erase(nums[i]);
            }
            else{
                mp[nums[i]] = nums[i] + 1;
            }
        }
        for(auto i : mp){
            ans += i.second;
        }
        return ans;
        
    }
};