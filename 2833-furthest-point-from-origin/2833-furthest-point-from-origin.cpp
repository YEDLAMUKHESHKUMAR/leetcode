class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int tot_underscores=0;
        int distance=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='_'){
                tot_underscores++;
            }
            else if(s[i]=='R'){
                distance++;
            }
            else{
                distance--;
            }
        }
        if(tot_underscores==0) return abs(distance);
        if(distance>0){
            return distance+tot_underscores;
        }
        else if(distance<0){
            return abs(distance)+tot_underscores;
        }
        else{
            return tot_underscores;
        }
    }
};