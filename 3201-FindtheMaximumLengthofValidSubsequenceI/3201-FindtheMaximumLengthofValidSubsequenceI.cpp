// Last updated: 7/16/2025, 11:10:59 AM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0, oddEven = 0, evenOdd = 0;
        bool needEven = false;
        if(nums[0] % 2 == 0) {
            evenOdd++;
            even++;
        }
        else {
            oddEven++;
            odd++;
            needEven = true;
        }
        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == 0){
                even++;
                if(needEven){
                    needEven = false;
                    oddEven++; evenOdd++;
                }
            }
            else{
                odd++;
                if(!needEven){
                    needEven = true;
                    oddEven++; evenOdd++;
                }
            }
        }
        return max({odd, even, oddEven, evenOdd});

    }
};