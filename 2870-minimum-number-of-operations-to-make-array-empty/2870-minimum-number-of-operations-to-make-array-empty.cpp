class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int minOperations=0;
        for(auto i:mp){
            
            if(i.second==1) return -1;
            minOperations+=(i.second/3);
            if(i.second%3!=0){
                minOperations++;
            }  
        }
        return minOperations;
    }
};