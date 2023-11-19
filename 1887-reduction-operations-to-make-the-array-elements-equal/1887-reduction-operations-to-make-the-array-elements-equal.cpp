class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> mp;     // see notes
        long long totalOperations = 0, prevOperations = 0;  // :)  
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(auto i=mp.end();i!=mp.begin();i--){
            totalOperations += (i->second + prevOperations);
            prevOperations = i->second + prevOperations;
            
        }
        return totalOperations;
    }
};