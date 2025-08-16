// Last updated: 8/16/2025, 11:40:22 PM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int rows = (n / (2 * k + 1));
        int rowRem =  (n % (2 * k + 1));
        int cols = (m / (2 * k + 1));
        int colRem = (m % (2 * k + 1));

        if(rowRem != 0) rows++;
        if(colRem != 0 ) cols++;
        return rows * cols;
        // return ( (n / (k + 1)) * (m / ( k + 1 )) );
    }
};