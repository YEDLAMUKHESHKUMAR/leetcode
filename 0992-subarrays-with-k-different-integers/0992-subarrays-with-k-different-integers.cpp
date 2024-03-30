class Solution {
public:
int solve(vector<int> &nums,int k){
    int ans = 0 ;
    int j = 0 , distCount = 0 , n = nums.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp[nums[i]] == 0){
            distCount++;
        }
        mp[nums[i]]++;
        while(j<n && distCount > k){
            mp[nums[j]]--;
            if(mp[nums[j]] == 0) distCount-- ;
            j++;
        }
        ans += i - j + 1; 
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};