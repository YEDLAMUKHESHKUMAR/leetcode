class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k>nums.size()){
            vector<int> a(nums.size(),-1);
            return a;
        }
        long long denom=2*k+1;
        int n=nums.size();
        long long prefix[n] ;
        vector<int> ans;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        for(int i=0;i<k;i++){
            ans.push_back(-1);
        }
        long long delete_sum=0;
        sum=0;
        for(int i=k;i<n;i++){
            if(n-i-1<k){
                ans.push_back(-1);
            }
            else{
                sum=(prefix[i+k]-delete_sum)/denom;
                ans.push_back(sum);
                delete_sum=prefix[i-k];
            }
        }
        return ans;
    }
};