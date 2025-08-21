// Last updated: 8/21/2025, 11:19:07 AM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> suffix(n, n);
        for(int i = n - 1; i >= 0 ;i--){
            while(!st.empty() && heights[i] <= heights[st.top()] ){
                st.pop();
            }
            if(!st.empty()) suffix[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> prefix(n, -1);
        for(int i = 0 ; i < n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()] ){
                st.pop();
            }
            if(!st.empty()) prefix[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        prefix[0] = -1;
        suffix[n - 1] = n;
        for(int i = 0; i < n ;i++){
            int left = i - prefix[i];
            int right = suffix[i] - i - 1;
            ans = max(ans , (left + right) * heights[i] );
        }
        for(auto i : prefix) cout<<i<<" ";
        cout<<endl;
        for(auto i : suffix) cout<<i<<" ";

        return ans;
        
    }
};