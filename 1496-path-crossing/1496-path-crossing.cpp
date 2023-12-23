class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> mp;        // :)
        int n = path.size();
        mp[{0,0}]++;
        int x = 0 , y = 0;
        for(int i=0;i<n;i++){
            if(path[i] == 'N'){
                x++;
            }
            else if(path[i] == 'S'){
                x--;
            }
            else if(path[i] == 'E'){
                y++;
            }
            else {
                y--;
            }
            mp[{x,y}]++;
            if(mp[{x,y}] > 1){
                return true;
            }
        }
        return false;
    }
};