class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }
            
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
        }
        
        return biggest * secondBiggest - smallest * secondSmallest;
        // int m1= INT_MAX , m2 = INT_MAX;
        // int m3 = 0, m4 = 0;
        // int n = nums.size();                 -_- ...why not working :()
        // int fMin , fMax ;
        // for(int i = 0;i<n;i++){
        //     if(nums[i] > m3){
        //         m4 = m3;
        //         m3 = nums[i];
        //     }
        //     else{
        //         m4 = max(m4,nums[i]);
        //     }
        //     if(nums[i] < m1 ){
        //         m2 = m1 ;
        //         m1 = nums[i];
        //     }
        //     else{
        //         m2 = min(m2,nums[i]);
        //     }
        // }
        // return (m3*m4) - (m2-m1);

    }
};