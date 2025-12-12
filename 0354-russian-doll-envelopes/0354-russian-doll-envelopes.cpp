class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        multiset<int> st;
        st.insert(nums[0][1]);
        for(int i = 1 ; i < n; i++){
            if(nums[i][0] > nums[i - 1][0] && nums[i][1] > *st.rbegin()){
                st.insert(nums[i][1]);
            }
            else{
                auto it = st.lower_bound(nums[i][1]);
                st.erase(it);
                st.insert(nums[i][1]);
            }
        }
        return (int)st.size();

    }
};