class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        // bool check=false;
        // for(i=n-2;i>=0;i--){  we dont have to run inner while loop ....since because we know where to 
        //     if(nums[i]<nums[i+1]){    // stop ...stop if < occurs...and then do a seperate while loop
        //         j=n-1;
        //         while(j>i){
        //             if(nums[i]<nums[j]){
        //                 swap(nums[i],nums[j]);
        //                 check=true;
        //                 break;
        //             }
        //             j--;
        //         }
        //         if(check==true){
        //             break;
        //         }
        //     }
        // }
        // reverse(nums.begin()+i+1,nums.end());
        bool check=false;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                check=true;
                break;
            }
        }
        if(check==false){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(j=n-1;j>i;j--){
            if(nums[i]<nums[j]){
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());

        
    }
};