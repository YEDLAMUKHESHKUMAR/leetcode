class Solution {
public:
    double myPow(double x, int n) {
        long long temp = n;
        double ans = 1.0;
        if(temp<0){
            temp = -1 * temp;
        }
        while(temp!=0){
            if(temp%2==0){
                x=x*x;
                temp=temp/2;
            }
            else{
                ans *= x;
                temp--;
            }
        }
        if(n<0){
            ans = (double)(1.0)/(double)ans;
        }
        return ans;

    }
};