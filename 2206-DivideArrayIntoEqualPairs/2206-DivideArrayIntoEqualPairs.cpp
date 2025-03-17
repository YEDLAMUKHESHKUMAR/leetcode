class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> mp(501, true);
        for(auto i : nums){
            mp[i] = !mp[i] ;
        }
        for(auto i : mp){
            if(i == false) return false;
        }
        return true;
    }
};