class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> check;
        unordered_map<int,int> ind;
        int degree=INT_MIN;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>=degree) degree=freq[nums[i]];
        }
        int maxi=INT_MAX;
        // return degree;
        for(int i=0;i<nums.size();i++){
            check[nums[i]]++;
            if(check[nums[i]]==degree){
                maxi=min(maxi,i-ind[nums[i]]+1);
            }
            if(ind.find(nums[i])==ind.end()){
                ind[nums[i]]=i;
            }

        }
        return maxi;
    }
};