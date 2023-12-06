class Solution {
public:
    int totalMoney(int n) {
        int decrease = 0;
        int ans = 0;
        int weeks = 0 , dollar = 1 ;
        while(n>0){
            int temp = 7 ;
            if(n - 7 < 0 ){
                temp = n;
            }
            temp+=weeks;
            ans = ans + (temp*(temp+1)/2) - decrease;
            weeks++;
            decrease+=dollar;
            dollar++;
            n-=7;
        }
        return ans;
    }
};