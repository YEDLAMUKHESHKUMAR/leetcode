// Last updated: 7/26/2025, 10:02:11 AM
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0; i < n ; i++){
            if(!st.empty() && nums[i] < st.top()) continue;
            st.push(nums[i]);
        }
        return (int)st.size();
    }
};