class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0) c++;
            mp[nums[i]]++;
            int x=nums[i];
            int reversed=0;
            while(x!=0){
                reversed=reversed*10+(x%10);
                x=x/10;
            }
            if(mp[reversed]==0) c++;
            mp[reversed]++;
        }
        return c;
    }
};