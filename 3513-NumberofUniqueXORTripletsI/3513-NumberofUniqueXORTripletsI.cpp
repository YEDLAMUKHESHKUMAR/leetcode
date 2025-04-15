// Last updated: 4/15/2025, 10:29:09 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int maxi = n; // permutation ...right
        
        int setBits = 0 , lastSetBit = 0;
        for(int pos = 0; pos < 32 ; pos++){
            if( (maxi >> pos) & 1 ){
                setBits++;
                lastSetBit = pos;
            }
        }
        lastSetBit++;
        return (1 << lastSetBit);

    }
};