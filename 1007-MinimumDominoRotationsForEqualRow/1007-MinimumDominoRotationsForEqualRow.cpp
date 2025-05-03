// Last updated: 5/3/2025, 10:26:25 AM
class Solution {
public:
    int solve(int t, vector<int> &tops, vector<int> &bottoms){
        int n = tops.size();
        int f = 0, s= 0 ;
        bool check1 = true;
        for(int i = 0; i < n ;i++){
            if(tops[i] != t && bottoms[i] != t) {
                check1 = false;
                // cout<<i<<endl;
                break;
            }
            if(tops[i] == t) f++;
            if(bottoms[i] == t) s++;
            // 1 0 1 0 1 1 0
            // 1 1 0 1 1 0 1
        }
        if(check1 == false) return -1;
        return min(n - f, n - s);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int t = tops[0];
        int b = bottoms[0];
        int topGuy = solve(t, tops, bottoms);
        int bottomGuy = solve(b, tops, bottoms);
        cout<<topGuy<<" "<<bottomGuy<<endl;
        if(topGuy == -1 && bottomGuy == -1) return -1;
        if(topGuy == -1) return bottomGuy;
        return topGuy;


        
        
        
        

    }
};