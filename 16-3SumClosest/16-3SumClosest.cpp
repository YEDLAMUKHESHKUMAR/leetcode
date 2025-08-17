// Last updated: 8/18/2025, 3:13:33 AM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n ; i++){
            int x = nums[i];
            for(int j = i + 1; j < n - 1 ;j++){
                int y = nums[j];
                int xplusy = x + y;
                int tar = target - xplusy;
                int ind1 = n - 1, ind2 = n - 1;
                auto it = upper_bound(nums.begin() + j + 1, nums.end(), tar);
                if(it != nums.end()) {
                    it--;
                    ind1 = it - nums.begin();
                    
                }
                if(ind1 == j){
                    ind1 = min(n - 1, j + 1);
                }
                auto it2 = lower_bound(nums.begin() + j + 1, nums.end(), tar);
                if(it2 != nums.end()){
                    ind2 = it2 - nums.begin();
                }
        // -4 -1 1 2
                int t = target - xplusy;
                int diff1 = abs(t - nums[ind1]);
                int diff2 = abs(t - nums[ind2]);

                int close = min(diff1, diff2);
                // cout<<i<<" "<<j<<" "<<sum<<" ..."<<ind1<<" "<<ind2<<" "<<close<<endl;
                if(close < closest) {
                    closest = close;
                    sum = xplusy;
                    if(diff1 < diff2){
                        sum += nums[ind1];
                    }
                    else {
                        // cout<<i<<" "<<j<<" "<<sum<<" ..."<<ind2<<" :2"<<endl;
                        sum += nums[ind2];
                    }
                }

            }

        }
        return sum;

    }
};