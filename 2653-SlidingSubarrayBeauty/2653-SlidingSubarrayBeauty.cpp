class Solution {
public:
    void getXthElement(vector<int> &mp, vector<int> &ans, int x){
        int count = 0;
        bool flag = false;
        for(int i = 50; i>=0;i--){  // just 50 elements :)
            if(mp[i] > 0 ){
                count+=mp[i];  // dup values...
            }
            if(count >= x) {
                ans.push_back(-1 * i);
                flag = true;
                break;
            } 
        }
        if(!flag) ans.push_back(0);
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        // lol, use constraints , max 50 -ve nums..
        int n = nums.size();
        vector<int> mp(51, 0);
        vector<int> ans;
        for(int i = 0; i<k;i++){
            if(nums[i] < 0) mp[abs(nums[i])]++;
        }
        getXthElement(mp, ans,x);
        for(int i = k ; i<n;i++){
            if(nums[i - k ] < 0){
                mp[abs(nums[i - k])]--;
            }
            if(nums[i] < 0){
                mp[abs(nums[i])]++;
            }

            getXthElement(mp, ans,x);
        
        }

        return ans;
    }
};