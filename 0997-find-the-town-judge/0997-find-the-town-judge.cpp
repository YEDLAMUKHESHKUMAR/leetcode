class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> mp;   // :) 
        unordered_map<int,int> freq;
        // unordered_map<int,int> tot;
    if(n == 1) return 1;
        int m = trust.size();
        for(int i=0;i<m;i++){ 
            mp[trust[i][0]].push_back(trust[i][1]);
            freq[trust[i][1]]++;
            // tot[trust[i][0]]++;
            
        }
        
        int ans = -1;
        // int ch = tot.size();
        for(int i=1;i<=n;i++){
            if(mp[i].empty()){
                if(freq[i] == n-1) return i;
                return -1;
            }
        }
        return ans;

    }
};