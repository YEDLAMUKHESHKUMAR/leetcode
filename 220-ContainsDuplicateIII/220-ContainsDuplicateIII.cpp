// Last updated: 6/28/2025, 10:23:53 PM
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // 3 1 2 3 1 1 2 2 3
        // 0 1 2 3 4 5 6 7 8  
        int n = nums.size();
        multiset<long long> ms;
        
        for(int i = 0; i< n;i++){
            if (i > indexDiff) {
                ms.erase(ms.find(nums[i - indexDiff - 1]));
            }

            auto it = ms.lower_bound( (long long)nums[i] - 1LL * valueDiff);
            if(it != ms.end() && abs(*it - nums[i] ) <= valueDiff){
                return true;
            } 

            
            ms.insert(nums[i]);

        }
        return false;
    }
};