class Solution {
public:
    int pivotInteger(int n) {
        int sumOfN = (n*(n+1)/2);
        int curr = 1;
        int sum = 0;
        for(int i = 1;i<=n;i++){
            sum+=i;
            int right = sumOfN - sum;
            if(sum == right + i) return i;  
        }
        return -1;

    }
};