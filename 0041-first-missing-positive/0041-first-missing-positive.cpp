// void do_swap(int &current_element,int &actual_element){
//     int temp = current_element;
//     current_element = actual_element;
//     actual_element = current_element;
// }
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int current_element;
        for(int i=0;i<n;i++){
            
         while(nums[i]>0 && nums[i]<=n && nums[i] !=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            int current_element=nums[i];
            int current_index=i+1;
            if(current_element!=current_index){
                return current_index;
            }
        }
        return n+1;
    }
};