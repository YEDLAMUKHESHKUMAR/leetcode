class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<a.size();i++){
            if(st.empty() || (a[i]>0 && (st.top()>0 || st.top()<0)) || (a[i]<0 && st.top()<0)){
                st.push(a[i]);
            }
            else{
                while(!st.empty() && (a[i]<0 && st.top()>0) && (abs(a[i])>st.top())){
                    st.pop();
                }
                if(!st.empty() && abs(a[i])==st.top()){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(a[i]);
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};