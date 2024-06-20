class Solution {
public:
    bool solve(int minMF,int balls, vector<int> &pos){
        int n = pos.size();
        int lastBallPos = pos[0];
        balls--;
        for(int i = 1 ; i < n ; i++){
            if(pos[i] - lastBallPos >= minMF){
                lastBallPos = pos[i];
                balls--;
            }
            if(balls == 0 ) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxi = position[0],mini = position[0];  // :)
        int n = position.size();
        for(int i  = 0 ;i <n;i++){
            maxi = max(maxi,position[i]);
            mini = min(mini,position[i]);
        }
        int st = 1 ;
        int end = maxi - mini ;
        int magneticForce = 0;
        while(st <= end){
            int mid = (st + end) / 2 ;
            if(solve(mid,m,position) == true){
                magneticForce = mid;
                st = mid + 1 ;
            }
            else {
                end = mid - 1 ;
            }
        }
        return magneticForce;
    }
};