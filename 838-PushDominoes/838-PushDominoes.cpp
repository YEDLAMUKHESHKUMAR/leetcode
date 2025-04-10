// Last updated: 4/10/2025, 7:51:29 PM
class Solution {
public:
    string pushDominoes(string dominoes) {
        // .L.RRRRLRRRL..
        // 0123456789
        // LL.RLLLLRLLL.. 
        // LL.R
        // R....L
        // right then left.... then only they coincide...
        int n = dominoes.size(), r = -1;
        vector<pair<int,int>> RL;
        string ans = "";
        bool R = false;
        char put = '.';
        for(int i = 0; i < n ;i++){
            //   r .....l
            //     123456
            //     654321
            if(dominoes[i] == 'L' && R == true){
                RL.push_back({r, i}); R = false; put = 'L';
            }
            if(dominoes[i] == 'R') {
                R = true; r = i; put = 'R';
            }
            if(put == 'R') ans += "R";
            else ans += dominoes[i];

        }
        put = '.';
        for(int i = n-1; i>= 0; i-- ){
            if(dominoes[i] == 'L') put = 'L';
            else if(dominoes[i] == 'R') put = 'R';
            if(put == 'L') ans[i] = 'L';
            else if(ans[i] != 'R') ans[i] = dominoes[i]; 
        }
        for(auto i : RL){
            int st = i.first;
            int end = i.second;
            int size = end - st - 1;
            int cnt = size / 2;
            int ind = st + 1;
            while(cnt--){
                ans[ind++] = 'R';
            }
            // cout<<st<<" : "<<end<<endl;
            if(size % 2 == 1) ans[(st + end) / 2] = '.';
        }
        return ans;

    }
};