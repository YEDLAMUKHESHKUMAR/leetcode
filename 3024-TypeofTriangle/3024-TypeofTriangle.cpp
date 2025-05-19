// Last updated: 5/19/2025, 9:40:22 AM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a   = nums[0] ;
        int b = nums[1];
        int c = nums[2];
        if(a==b && b==c){
            return "equilateral";
        }
         
        int sum1 = a+b;
        int sum2 = b+c;
        int sum3 = a+c;
        if(sum1>c && sum2>a && sum3>b) {
            if(a==b || b==c || a==c  ){
             return "isosceles";
        }
            return "scalene";
        }
        return "none";
        // else if(b==c){
        //     if(b!=a){
        //         return "isosceles";
        //     }
        //     return "none";
        // }
        //  else if(a==c  ){
        //     if(b!=c) return "isosceles";
        //     return "none";
        // }
        // return "scalene";
        

    }
};