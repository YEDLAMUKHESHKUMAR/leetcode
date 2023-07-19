class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0 || nums.size()==1) return false;
        unordered_map<int,int> mp;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(c==1) break;
            if(mp[nums[i]]!=0){
                if((i+1)-mp[nums[i]]<=k){
                    c++;
                }
                // mp[nums[i]]=i+1;
            }
            // else{
            mp[nums[i]]=i+1;
            // }

        }
        if(c>=1) return true;
        return false;
    }
};