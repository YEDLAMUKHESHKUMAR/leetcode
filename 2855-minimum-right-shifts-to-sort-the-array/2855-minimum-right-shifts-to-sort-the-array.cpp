class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int i=1,shifts=n;
        bool increase=true;
        while(i<n){
            if(nums[i]<nums[i-1] && increase==true){
                shifts=i;
                increase=false;
            }
            else if(increase == false && (nums[i]<nums[i-1] || nums[i]>nums[0])){
                return -1;
            }
            i++;
            
        }
        return n-shifts;
        // while(i<n)
    }
};