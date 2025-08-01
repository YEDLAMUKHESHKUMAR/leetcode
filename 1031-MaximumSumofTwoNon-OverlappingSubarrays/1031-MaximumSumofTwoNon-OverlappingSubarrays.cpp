// Last updated: 8/1/2025, 11:59:23 AM
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1 , 0);
        int sum = 0;
        for(int i = 0; i < firstLen ; i++){
            sum += nums[i];
        }
        prefix[firstLen - 1] = sum;
        int maxSum = sum;
        for(int i = firstLen ; i < n ; i++){
            sum -= nums[i - firstLen];
            sum += nums[i];
            maxSum = max(maxSum, sum);
            prefix[i] = maxSum;
        }
        sum = 0;
        for(int i = n - 1; i > (n - 1 - firstLen) ; i--){
            sum += nums[i];
        }
        suffix[n - firstLen] = sum;
        maxSum = sum;
        for(int i = n - firstLen - 1 ; i >= 0 ; i--){
            sum -= nums[ i + firstLen];
            sum += nums[i];
            maxSum = max(maxSum, sum);
            suffix[i] = maxSum;
        }
        sum = 0;
        // for(int i = 0; i < n ;i++){
        //     cout<<prefix[i]<<" ";
        // }
        // // sum = 0;
        // cout<<endl;
        // for(int i = 0; i < n ;i++){
        //     cout<<suffix[i]<<" ";
        // }
        
        for(int i = 0 ; i < secondLen; i++){
            sum += nums[i];
        }
        int ans = max(0, sum + suffix[secondLen] );
        for(int i = secondLen ; i < n ;i++){
            sum -= nums[i - secondLen];
            sum += nums[i];
            if(i + 1 < n ){
                ans = max(ans, sum + suffix[i + 1] );
            }
            if(i - secondLen >= firstLen - 1){
                ans = max(ans, sum + prefix[i - secondLen]);
            }

        }
        return ans;



    }
};