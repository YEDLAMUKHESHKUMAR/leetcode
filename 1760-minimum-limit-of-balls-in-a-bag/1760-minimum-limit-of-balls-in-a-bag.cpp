class Solution {
public:
    int solve(vector<int> &arr,int mid){
        int operations=0;
        for(int i=0;i<arr.size();i++){
            operations+= (arr[i]-1)/mid;
        }
        return operations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi = *max_element(nums.begin(),nums.end());
        int low = 1 , high = 1e9;
        int ans=1;
        while(low<=high){
            int mid=(low+high)/2;
            int operations = solve(nums,mid);
            if(operations >maxOperations){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};