class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,mid=0;
        while(l<h){
            mid=(l+h)/2;
            if(nums[mid]>nums[h]){
                l=mid+1;             // i've tried the solution in different manner
            }                        // i tried to find max element instead of min
            else{                    // i was wondering why it was not working .... but  
                h=mid;               // but i got the same thought without solution ... that's  
            }                        //     ..... enough :)
        }
        int see=l;
        l=0,h=nums.size()-1;
        if(nums[see]<=target && target<=nums[h]){
            l=see;
        }
        else{
            h=see;
        }
        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
        
    }
};