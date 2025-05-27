// Last updated: 5/27/2025, 9:47:51 AM
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = (n * ( n + 1) / 2);
        int div = n / m;
        int divisible = m * ( div * ( div + 1 ) / 2  );
        int notDivisible = totalSum - divisible;
        return notDivisible - divisible;
    }
};