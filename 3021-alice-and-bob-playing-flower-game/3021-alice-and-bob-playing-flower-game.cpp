class Solution {
public:
    long long flowerGame(int n, int m) {
        // easy peasy.... just do this : 
        // we know alice can only win when the total number of flowers is odd...means he should pick last
        // you can only get odd if 
        // 1.) x is odd , y is even (x + y is also odd ----> eg:3+4=7)
        // 2.) x is even , y is odd (x + y is also odd ----> eg:8+7=15)
        // (odd from x * even form y) + (even from x * odd from y) ;
        long long oddx=0, eveny=0, evenx=0, oddy=0;
        evenx = n/2;
        oddx = n%2 == 0 ? evenx : evenx+1;
        eveny = m/2;
        oddy = m%2 == 0 ? eveny : eveny+1;
        return oddx*eveny + evenx*oddy;
    }
};