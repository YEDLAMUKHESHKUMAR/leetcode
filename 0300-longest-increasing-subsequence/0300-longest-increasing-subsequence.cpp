class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        st.insert(nums[0]);
        for(int i = 1; i < n ;i++){
            if(nums[i] > *st.rbegin()){
                st.insert(nums[i]);
            }
            else{
                auto it = st.lower_bound(nums[i]);
                st.erase(*it);
                st.insert(nums[i]);
            }
        }
        return (int)st.size();
    }
};