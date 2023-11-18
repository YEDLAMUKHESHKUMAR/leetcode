class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long i = 0,n =nums.size();
        long ans = 1 , sum = 0;
        for(int j=0;j<n;j++){       // finding if it is valid or not while traversing and maintaining the sliding window
            sum+=nums[j];
            while((j - i + 1)*nums[j] - sum > k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1>ans){
                ans = j-i+1;
            }
            // ans = max(ans,j - i + 1);
        }
        return ans;
    }
};