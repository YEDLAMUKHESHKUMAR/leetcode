class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(maxi<nums[i]){
                maxi=nums[i];
            }
        }
        if(maxi>=n) return false;
        for(auto i:mp){
            if(i.first==maxi){
                if(i.second!=2) return false;
                continue;
            }
            else if(i.second>1 ) return false;
        }
        return true;
    }
};