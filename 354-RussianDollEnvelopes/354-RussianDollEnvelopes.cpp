// Last updated: 6/19/2025, 6:51:17 PM
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]==b[0] ? a[1] > b[1]  : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        multiset<int> st;
        st.insert(envelopes[0][1]);
        
        for(int i = 1; i < n;i++){
            if( envelopes[i][0] > envelopes[i-1][0] && envelopes[i][1] > *st.rbegin() ){
                st.insert(envelopes[i][1]);
            }
            else{
                auto it = st.lower_bound(envelopes[i][1]);
                if(it!=st.end()){
                    st.erase(it);
                    st.insert(envelopes[i][1]);
                }
            }
            
            // cout<<st.size()<<" ";
        }
        return st.size();

    }
};