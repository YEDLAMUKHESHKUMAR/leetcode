class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // see notes 
        if(sx==fx && sy==fy){
            if(t!=1) return true;    // :) :) :)
            return false;
        }
        int yDistance = abs(sy-fy);
        if(sx>fx){
            sx = sx - yDistance; 
            if(sx<=fx) sx=fx;
        }
        else if(sx<fx){
            sx = sx + yDistance;
            if(sx>=fx) sx=fx; 
        }
        int xDistance = abs(sx-fx);
        int total = yDistance + xDistance;
        if(total>t) return false;
        return true; 
    }
};