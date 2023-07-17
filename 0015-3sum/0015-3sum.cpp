class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i,j,k;
        int sum;      // idea own
        set<vector<int>> s;
        vector<vector<int>> v;
        for(i=0;i<nums.size();i++){
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]}); // set will automatically delete duplicates          
                    k--; 
                    j++;
                }
                else if(sum<0){
                    j++;    // we no need to check for every element becoz it is sorted ... at right side we have greater element .. while we are adding with greater element if we get <0 ..no need to check for the rest of elements ...
                }
                else{
                    k--;
                }
            }
        }
        for(auto i:s){
            v.push_back(i);
        }
        return v;
    }
};