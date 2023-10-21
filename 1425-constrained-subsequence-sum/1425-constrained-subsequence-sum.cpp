class Solution {
public:
    // int solve(int prev,int i,vector<int> &nums,int k){
    //     if(i>=nums.size()){
    //         return 0;
    //     }
    //     int res=0;
    //     if(prev==-1 || i-prev<=k){
    //         int take= nums[i]+solve(i,i+1,nums,k);
    //         int notTake = solve(prev,i+1,nums,k);
    //         res = max(take,notTake);
    //     }
    //     return res;
    // }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // return solve(-1,0,nums,k);
        priority_queue<pair<int, int>> heap;      
        heap.push({nums[0],0});
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            while( i - heap.top().second > k ){  // if maximum sum is out of range , we'll try for next maximum sum 
                heap.pop();
            }
            int curr = max(0,heap.top().first) + nums[i];
            ans = max(ans,curr);
            heap.push({curr,i}); // stores maximum sum on the top, every time 
        }
        return ans;

    }
};