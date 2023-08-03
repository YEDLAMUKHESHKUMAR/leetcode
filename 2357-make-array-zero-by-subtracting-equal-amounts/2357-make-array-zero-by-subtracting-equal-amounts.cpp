class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // we can do this using sort or maps or priority queue...
        sort(nums.begin(),nums.end());
        int count=0,carry=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]= nums[i]-carry;
            if(nums[i]!=0){
                count++;
                carry+=nums[i];
            }
        }
        return count;
    }
};