class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // using bit manipulation 
        int n = nums.size();
        int pow = 1<<n;
        vector<vector<int>> ans;
        for(int i = 0;i<pow;i++){
            int n = i;
            int ind = 0;
            vector<int> temp;
            while(n > 0){
                if(n & 1 == 1 ){
                    temp.push_back(nums[ind]);
                }
                ind++;
                n = n>>1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};