// Last updated: 6/6/2025, 11:20:17 AM
class Solution {
public:
    void solve(int ns, stack<int> &st, string& ans){
        while(!st.empty() && st.top() <= ns){
            ans += (char(st.top() + 'a'));
            st.pop();
        }
    }
    string robotWithString(string s) {
        // b a c
        // b

        // bdda
        // bdda
        int n = s.size();
        stack<int> st;
        vector<int> nextSmaller(n, -1);
        int smaller = s[n-1] - 'a';
        for(int i = n - 2 ; i>= 0; i--){
            smaller = min(smaller, s[i] - 'a' );
            nextSmaller[i] = smaller;
        }
        string ans = "";
        for(int i = 0; i < n ;i++){
            int ch = s[i] - 'a';
            int ns = nextSmaller[i];
            bool isNS = (ns == -1 ? false : true);
            if(!isNS){
                ns = ch;
                solve(ns, st, ans);
                ans += (char(ns + 'a'));
            }
            else{
                solve(ns, st, ans);
                st.push(ch);
            }

        }
        while(!st.empty()){
            ans += (char(st.top() + 'a'));
            st.pop();
        }
        return ans;
    }
};