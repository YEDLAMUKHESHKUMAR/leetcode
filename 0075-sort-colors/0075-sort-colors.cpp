class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zero=0,two=n-1;
        int i=0;
        while(i<=two){
            if(nums[i]==0){
                swap(nums[i],nums[zero]);
                zero++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[two]);
                two--;
                i--;
            }
            i++;
            
        }
    }
}; 