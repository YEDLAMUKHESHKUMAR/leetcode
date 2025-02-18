class Solution {
public:
    void solve(int i, string s, string &tiles, vector<int> &vis, set<string> &st){
        st.insert(s);
        // cout<<s<<endl;
        for(int j = 0; j<tiles.size();j++){
            if(!vis[j]){
                vis[j] = 1;
                solve(j + 1, s + tiles[j], tiles , vis , st);
                vis[j] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int> vis(n, 0 );
        set<string> st;
        solve(0, "", tiles, vis, st);
        st.erase("");
        return st.size();
    }
};