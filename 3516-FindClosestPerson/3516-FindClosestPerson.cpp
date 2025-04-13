// Last updated: 4/13/2025, 9:33:26 AM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(z - x);
        int d2 = abs(z - y);
        if(x == y) return 0;
        if((z >= x && z <= y) || (z >= y && z <= x)){
            if(d1 == d2) return 0;
            if(d1 < d2) return 1;
            return 2;
        }
        if(d1 < d2) return 1;
        return 2;
        
    }
};