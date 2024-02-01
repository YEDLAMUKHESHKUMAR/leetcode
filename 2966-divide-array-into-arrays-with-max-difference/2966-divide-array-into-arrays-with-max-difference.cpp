class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int j = 0;
        int i = j;
        for(i=0;i<n;i+=3){
            vector<int> part;
            part.push_back(nums[i]);
            j = i+1;
            int c = 0;
            while(i<n && c<2 && j<n){
                int diff = nums[j] - nums[j-1];
                if(diff > k) return {};
                part.push_back(nums[j]);
                j++;
                c++;
            }
            if(part[part.size()-1] - part[0] > k) return {};
            ans.push_back(part);
            
        }
        return ans;
    }
};