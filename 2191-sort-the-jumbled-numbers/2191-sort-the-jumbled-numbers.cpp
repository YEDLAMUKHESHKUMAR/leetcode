class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int pos = 1 ;
            int num = nums[i];
            int res = 0;
            while(num!=0){
                int mapped = mapping[num % 10];
                res = mapped * pos + res; 
                pos *= 10;
                num /= 10;
            }
            if(nums[i] == 0){
                res=mapping[0];
            }
            // mp.push_back({res,nums[i]}); // notes
            mp.push_back({res,i});

        }
        sort(mp.begin(),mp.end());
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(nums[i.second]);
        }
        return ans;
        
    }
};