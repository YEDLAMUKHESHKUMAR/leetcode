class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> winners;
        map<int,int> losers;
        vector<int> win;
        vector<int> lose;
        vector<vector<int>> ans;
        int n = matches.size();
        for(int i=0;i<n;i++){
            winners[matches[i][0]]++;
            losers[matches[i][1]]++;
        }
        for(auto i:winners){
            int player = i.first;
            if(losers.find(player) == losers.end()){
                win.push_back(player);
            }
        }
        for(auto i:losers){
            if(i.second ==1 ){
                lose.push_back(i.first);
            }
        }
        ans.push_back(win);
        ans.push_back(lose);
        return ans;


    }
};