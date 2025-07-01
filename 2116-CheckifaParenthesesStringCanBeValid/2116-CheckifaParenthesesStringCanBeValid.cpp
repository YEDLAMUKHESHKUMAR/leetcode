// Last updated: 7/1/2025, 10:11:15 PM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        stack<int> st;
        int balanced = 0;
        for(int i = 0; i < n;i++){
            if( locked[i] == '1' ){
                if(s[i] == '(') st.push(i);
                else{
                    if( !st.empty() && s[ st.top() ] == '(' ) {
                        st.pop();
                        balanced+=2;
                    }
                    else st.push(i);
                }
            }
        }
        int i = n - 1;
        for( i = n - 1; i >= 0 && !st.empty(); i--){
            if(s[st.top()] == ')' ) break;
            if(locked[i] == '0'){
                if( st.top() > i ) return false;
                st.pop();
                balanced += 2; 
            }
        }
        // cout<<st.size();
        for(int j = i;  j >= 0 && !st.empty();j--){
            if(locked[j] == '0'){
                cout<<st.top()<<" ";
                if(j < st.top()){
                    st.pop();
                    balanced += 2;
                }
            }
        }
        // cout<<1;
        if(!st.empty()) return false;
        int left = n - balanced;
        if(left % 2 != 0) return false;
        return true;

    }
};