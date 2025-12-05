class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        for(int i = 0 ; i < n - 1; i++){
            if(directions[i] == 'R' && directions[i + 1] == 'L'){
                ans += 2;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
        }
        bool consider = false;
        for(int i = 0; i < n ;i++){
            if(directions[i] == 'L' && consider) ans++;
            if(directions[i] == 'R' || directions[i] == 'S'){
                consider = true;
            }
        }
        consider = false;
        for(int i = n - 1; i >= 0 ; i--){
            if(directions[i] == 'R' && consider) ans++;
            if(directions[i] == 'L' || directions[i] == 'S'){
                consider = true;
            }
        }
        return ans; 

        
        return 1;
    }
};