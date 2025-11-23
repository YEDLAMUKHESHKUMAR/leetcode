class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       
        int n = nums.size();
        int ans = 0, sum = 0;;
        sort(nums.begin(), nums.end());
        vector<int> ones, twos;
        for(int i = 0; i < n ;i++){
            sum += nums[i];
            if(nums[i] % 3 == 0){
                ans += nums[i];
            }
            else if(nums[i] % 3 == 1){
                ones.push_back(nums[i]);
                
            }
            else twos.push_back(nums[i]);
        }
        if(sum % 3 == 0) return sum;
        int m1 = ones.size(), m2 = twos.size();
        vector<int> combined;
        for(int i = 0; i < min(3, m1); i++){
            combined.push_back(ones[i]);
        }
        
        for(int i = 0; i < min(3, m2); i++){
            combined.push_back(twos[i]);
        }
        sort(combined.begin(), combined.end());
        for(int i = 0; i < combined.size(); i++){
            // cout<<combined[i]<< " ";
            int deleteSum = combined[i];
            if((sum - deleteSum) % 3 == 0) ans = max(ans, sum - deleteSum  );       
            for(int j = i + 1; j < combined.size(); j++){
                int newSum = sum - deleteSum - combined[j];
                if(newSum % 3 == 0) ans = max(ans, newSum  );       
            }
        }
        return ans;
        // notes




    }
};