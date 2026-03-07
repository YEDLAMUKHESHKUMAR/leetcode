class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        int currIndex = 0;
        int deleted = 0;
        for(int i = 0; i < n ; i++){
            if(!st.empty() && (st.top().first % 2 == 0 && nums[i] == st.top().second) ) deleted++;
            else {
                st.push({currIndex, nums[i]});
                currIndex++;
            }
            
        }
        // cout<<st.size();
        // 0 1 2 
        if((n - deleted) % 2 == 1) deleted++;
        return deleted;
    }
};