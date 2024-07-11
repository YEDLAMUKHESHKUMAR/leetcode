class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n = s.size();
        st.push("");
        string temp = "";
        for(int i = 0;i<n;i++){    // notes :)
            if(s[i] == '('){
                st.push("");
            }
            else if(s[i] == ')'){
                string t = st.top();
                st.pop();
                reverse(t.begin(),t.end());
                st.top()+= t;
            }
            else{
                st.top() += s[i];
            }
        }
        return st.top();
    }
};