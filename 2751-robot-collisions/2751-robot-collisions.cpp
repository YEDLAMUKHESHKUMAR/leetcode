class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& healths, string dir) {
        // seems like balancing the paranthesis   
        stack<int> st;
        vector<pair<int,pair<int,char>>> v;    // notes
        int n = pos.size();
        for(int i = 0; i<n;i++){
            v.push_back({pos[i],{healths[i],dir[i]}});
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<n;i++){
            bool dead = false;
            while(!st.empty() && v[st.top()].second.second == 'R' && v[i].second.second == 'L'  ){
                if(v[st.top()].second.first > v[i].second.first){
                    v[st.top()].second.first--;
                    dead = true;
                    break;
                }
                else if(v[st.top()].second.first < v[i].second.first){
                    v[i].second.first--;
                    st.pop();
                }
                else{
                    st.pop();
                    dead = true;
                    break;
                }
            }
            if(dead == false){
                st.push(i);
            }
        }
        vector<int> ans;
        unordered_map<int,int> mp;
        while(!st.empty()){
            mp[v[st.top()].first] = v[st.top()].second.first ;
            st.pop();
        }
        for(int i = 0;i<n;i++){
            if(mp.find(pos[i]) != mp.end()){
                ans.push_back(mp[pos[i]]);
            }
        }
        return ans;

    }
};