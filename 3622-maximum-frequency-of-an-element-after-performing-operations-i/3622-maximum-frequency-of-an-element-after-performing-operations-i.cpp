class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        int m = 0;
        // notes
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            maxi = max(maxi,nums[i]);
            m = max(m,mp[nums[i]]);
            
        }
        if(k == 0) return m;  
        vector<int> prefix(maxi + 1);
        for(int i = 1; i<= maxi ;i++){ // not submitted in contest.... 
            int sum = prefix[i - 1] + mp[i];
            prefix[i] = sum;
        }
        int maxFreq = 0;
        for(int i = 0; i<= maxi; i++){  
            int currFreq = prefix[i];
            int left = prefix[0];
            int right = prefix[maxi];
            if(i > 0){
                currFreq -=  prefix[i-1];
                left = prefix[i-1];
            }
            if(i - k - 1 >=0 ){
                left -= prefix[i - k - 1];
            }
            if(i + k <= maxi){
                right = prefix[i + k];
            }
            right -= prefix[i];
            
            int temp = left + right;
            currFreq = currFreq + (temp <= op ? temp : op);
            maxFreq = max(maxFreq,currFreq);
        }
        return maxFreq;
        
    }
};