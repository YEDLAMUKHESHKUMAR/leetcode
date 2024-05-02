class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            int curr = -1*nums[i];
            if(mp.find(curr) != mp.end()){
                maxi = max(maxi,abs(curr));
            }
            mp[nums[i]]++;
        }
        if(maxi == INT_MIN) return -1;
        return maxi;
    }
};