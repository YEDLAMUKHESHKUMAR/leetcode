// Last updated: 8/18/2025, 2:16:21 PM
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        stack<pair<int,int>> sum; 
        int ans = 0;
        for(int i = 0; i < n ;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.empty()) {
                    sum.push({INT_MIN,INT_MIN});
                }
                else{
                    st.pop();
                    int add = 2;
                    int top = (st.empty() ? -1e8 : st.top());
                    while(!sum.empty() && sum.top().first > top){
                        add += sum.top().second;
                        sum.pop();
                    }
                    ans = max(ans, add);
                    sum.push({i, add});
                }
            }
        }
        return ans;
    }
};