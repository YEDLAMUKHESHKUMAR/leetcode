// Last updated: 6/3/2025, 6:17:54 PM
class Solution {
public:
    int minOperations(int n) {
        int conseOnes = 0, ans = 0;
        for(int pos = 0 ; pos < 32 ; pos++){
            int bit = ( ( n >> pos ) & 1 );
            if( bit == 0  ){
                if( conseOnes == 0 ) continue;
                if(conseOnes == 1) {
                    conseOnes = 0;
                    ans += 1;
                }
                else if( (pos < 31 &&  !( ( n >> (pos + 1) ) & 1) ) ){
                    ans += 2;
                    conseOnes = 0;
                }
                else {
                    ans += 1;
                    conseOnes = 1;
                }
            }
            else{
                conseOnes++;
            }
        }
        if(conseOnes == 1 ) ans++; 
        if(conseOnes > 1 ) ans += 2; 
        return ans;
    }
};