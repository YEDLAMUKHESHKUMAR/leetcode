int solve(int index,vector<int> &arr,vector<int> &dp){
    int size=arr.size();
    int prev=arr[0];
    int prev2=0;
    // dp[0]=arr[0];
    int take,notTake;
    for(int i=0;i<size;i++){
        take= arr[i];
        if(i>1) take+=prev2;
        notTake=0+prev;
        int curr=max(take,notTake);
        prev2=prev;
        prev=curr;
        // dp[i]=max(take,notTake);
    }
    return prev ;
    // if(index==n-1){
    //     return arr[n-1];
    // }
    // if(index>=n){
    //     return 0;
    // }
    // if(dp[index]!=-1){
    //     return dp[index];
    // }
    // int pick=arr[index]+solve(index+2,arr,n,dp);
    // int non_pick= 0+solve(index+1,arr,n,dp);
    // return dp[index]=max(pick,non_pick);
}
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        vector<int> dp(n,-1);
        return max(solve(0,temp1,dp),solve(0,temp2,dp));
        

    }
};