class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();
        stack<char> st;
        for(int i = 0; i<n;i++){
            st.push(s[i]);
            if(!st.empty() && st.size() >= m &&  st.top() == part[m-1]){
                string check = "";
                for(int j = 0; j<m;j++){
                    check += st.top();
                    st.pop();
                }
                reverse(check.begin(), check.end());
                if(check == part) continue;
                for(int j = 0; j < check.size() ; j++){
                    st.push(check[j]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};