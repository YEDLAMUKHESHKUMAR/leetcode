// Last updated: 6/1/2025, 11:27:01 AM
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        long long ans=1;int p=0;
        for(auto i:nums){
          if(target%i)return 0;
            
            
        }
        return 1;
    }
};