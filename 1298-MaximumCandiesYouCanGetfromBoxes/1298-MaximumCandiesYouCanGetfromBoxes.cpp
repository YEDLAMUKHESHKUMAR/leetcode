// Last updated: 6/3/2025, 9:26:55 PM
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, 
    vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int m = initialBoxes.size();
        queue<int> q;
        unordered_map<int,int> mp;
        for(int i = 0; i < m ; i++){
            if(status[initialBoxes[i]] == 0) mp[initialBoxes[i]]++;
            else q.push(initialBoxes[i]);
        }
        int ans = 0;
        vector<int> vis(n , 0);
        while(!q.empty()){
            int box = q.front();
            ans += candies[box];
            q.pop();
            for(auto key : keys[box]){
                if(mp[key] > 0) {
                    mp.erase(key);
                    q.push(key);
                }
                status[key] = 1;
            }
            for(auto currBox : containedBoxes[box]){
                if(status[currBox] == 1 && !vis[currBox]) q.push(currBox);
                else if(status[currBox] == 0) mp[currBox]++;
            }

        }
        return ans;
    }
};