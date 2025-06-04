// Last updated: 6/4/2025, 10:57:06 AM
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<pair<int,int>> q;
        // vector<int> dist(n, INT_MAX);
        // unordered_map<int,bool> vis;
        vector<int> vis(n , 0);
        q.push({0,0});
        unordered_map<int,vector<int>> mp;
        unordered_map<int,bool> vis2;
        for(int i = 0;  i< n ;i++){
            mp[arr[i]].push_back(i);
        }
        while(!q.empty()){
            int i = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(i == n - 1) return dist;
            if(vis[i] == true) continue;
            vis[i] = true;
            if(i + 1 < n && !vis[i + 1] ){
                q.push({i + 1, dist + 1});
            }
            if(i - 1 >= 0 && !vis[i - 1]){
                q.push({i - 1, dist + 1});
            }
            if(vis2[arr[i]] == false ){
                for(auto ind : mp[ arr[i] ]){
                    q.push({ind, dist + 1});
                } 
            }
            vis2[arr[i]] = true; 
            
        }
        return 1;

    }
};