class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix,suffix;
        vector<int>ans;
        int i,prod=1;
        prefix.push_back(1),suffix.push_back(1);
        for(i=0;i<nums.size()-1;i++){
            prod*=nums[i];
            prefix.push_back(prod);
        }
        prod=1;
        for(i=nums.size()-1;i>0;i--){
            prod*=nums[i];
            suffix.push_back(prod);
        }
        reverse(suffix.begin(),suffix.end());
        for(i=0;i<nums.size();i++){
            ans.push_back(prefix[i]*suffix[i]);
            
        }
        return ans;
    }
};