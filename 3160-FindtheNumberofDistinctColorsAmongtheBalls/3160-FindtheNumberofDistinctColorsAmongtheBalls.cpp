class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int qs = q.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> colors;
        vector<int> ans;
        for(int i = 0; i< qs ;i++){
            int ball = q[i][0];
            int col = q[i][1]; 
            if(mp.find(ball) != mp.end()){
                int prevColor = mp[ball];
                if(prevColor != col) {
                    colors[prevColor]--;
                    if(colors[prevColor] == 0) colors.erase(prevColor);
                    mp[ball] = col;
                    colors[col]++;
                }
            }
            else{
                colors[col]++;
                mp[ball] = col;
            }
            ans.push_back(colors.size());
        }
        return ans;
    }
};